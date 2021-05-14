(ns net.smrq.sigmar-keyboard.keyplate-3d
    (:require [scad-clj.scad :as scad]
              [scad-clj.model :refer :all :exclude [import use]]
              [net.smrq.sigmar-keyboard.keyplate :refer [keyplate]]))

(def plate-thickness 1.5)

(def keyplate-3d
  (extrude-linear {:height plate-thickness} keyplate))

(spit "scad/keyplate-3d.scad" (scad/write-scad keyplate-3d))