CWD := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

ifeq ($(OS),Windows_NT)
	REVERSE_SLASHES = $(subst /,\,$1)
	MKDIRP = if not exist $(call REVERSE_SLASHES,$1) (mkdir $(call REVERSE_SLASHES,$1))
	RMRF = if exist $(call REVERSE_SLASHES,$1) (rmdir /s /q $(call REVERSE_SLASHES,$1))
else
	MKDIRP = mkdir -p $1
	RMRF = rm -rf $1
endif

DOCKER_IMG := sigmar
ifneq ($(SKIP_DOCKER), true)
	RUN := docker run --rm -e SKIP_DOCKER=true -v $(CWD):/root/workspace $(DOCKER_IMG)
endif

SRCDIR := src/net/smrq/sigmar_keyboard
SCADDIR := scad
SVGDIR := svg
STLDIR := stl

all: $(STLDIR)/keyplate-3d.stl
.PHONY: all list clean docker format
.SECONDARY:

clean:
	$(call RMRF,$(SCADDIR))
	$(call RMRF,$(SVGDIR))
	$(call RMRF,$(STLDIR))

docker: Dockerfile
	docker build -t $(DOCKER_IMG) .

format:
	$(RUN) lein cljfmt fix

$(SCADDIR)/%.scad: $(SRCDIR)/%.clj
	$(call MKDIRP,$(@D))
	$(RUN) lein exec -p $<

$(SVGDIR)/%.svg: $(SCADDIR)/%.scad
	$(call MKDIRP,$(@D))
	$(RUN) openscad -o $@ $<
	$(RUN) sed -i -e 's/stroke="[^"]*"/stroke="rgb(0,0,255)"/; s/fill="[^"]*"/fill="rgb(255,255,255)"/; s/stroke-width="[^"]*"/stroke-width="0.01"/' $@

$(STLDIR)/%.stl: $(SCADDIR)/%.scad
	$(call MKDIRP,$(@D))
	$(RUN) openscad -o $@ $<
