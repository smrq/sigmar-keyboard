(ns net.smrq.sigmar-keyboard.keyplate-3d
    (:require [scad-clj.scad :as scad]
              [scad-clj.model :refer :all :exclude [import use]]
              [net.smrq.sigmar-keyboard.keyplate :refer [keyplate keyplate-base]]))

(def ideal-plate-thickness 1.5)
(def layer-resolution 0.2)
(def plate-thickness (* (quot ideal-plate-thickness layer-resolution) layer-resolution))

(def wall-thickness 3)
(def wall-height 10)

(def plate-main (extrude-linear {:height plate-thickness :center false} keyplate))
(def plate-walls (extrude-linear {:height (+ plate-thickness wall-height) :center false}
                   (difference keyplate-base (offset (- wall-thickness) keyplate-base))))

(def keyplate-3d
  (union 
    (translate [0 0 wall-height] plate-main)
    plate-walls))

(spit "scad/keyplate-3d.scad" (scad/write-scad keyplate-3d))