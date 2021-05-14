(ns net.smrq.sigmar-keyboard.keyplate
    (:require [scad-clj.scad :as scad]
              [scad-clj.model :refer :all :exclude [import use]]))

(def switch-hole-size 14)
(def switch-cap-size 18)
(def key-spacing 19.05)
(def flap-width 0.6)
(def flap-height 3.5)
(def gap-between-flaps 5)

(defn translate-u [[x y] & block]
  (apply translate [(* x key-spacing) (* y key-spacing)] block))

(defn keyswitch-hole [u-width u-height c]
  (union
    (square switch-hole-size switch-hole-size :center true)
    (->> (square (+ switch-hole-size (* 2 flap-width)) flap-height :center true)
         (translate [0 (/ (+ gap-between-flaps flap-height) -2)]))
    (->> (square (+ switch-hole-size (* 2 flap-width)) flap-height :center true)
         (translate [0 (/ (+ gap-between-flaps flap-height) 2)]))))

(defn keycap-area [u-width u-height c]
  (color c
    (square (- (* key-spacing u-width) (- key-spacing switch-cap-size))
            (- (* key-spacing u-height) (- key-spacing switch-cap-size)))))

(defn key-area [u-width u-height c]
  (square (* key-spacing u-width) (* key-spacing u-height)))

(defn column-y-positions [u-sizes]
  (map (fn [u height] (- height (/ u 2)))
       u-sizes
       (reductions + u-sizes)))

(defn position-column [u-sizes colors key]
  (map (fn [u-size color position] (translate-u [0 position] (key 1 u-size color)))
       u-sizes
       colors
       (column-y-positions u-sizes)))

(defn rgb [r g b]
  [(/ r 255) (/ g 255) (/ b 255)])

(defn position-keys [key]
  (let [c-rcs (rgb 220 162 200)
        c-rcj (rgb 166 152 197)
        c-vat (rgb 147 194 71)
        c-wan (rgb 232 231 227)]
    (translate-u [0.5 0]
      (translate-u [0 0] (position-column [1.75 1 1] [c-rcj c-wan c-wan] key))
      (translate-u [1 0] (position-column [1 1 1 1] [c-rcj c-wan c-wan c-wan] key))
      (translate-u [2 0.25] (position-column [1 1 1 1] [c-rcj c-wan c-wan c-wan] key))
      (translate-u [3 0.5] (position-column [1 1 1 1] [c-rcj c-wan c-wan c-wan] key))
      (translate-u [4 0.25] (position-column [1 1 1 1] [c-rcj c-wan c-wan c-wan] key))
      (translate-u [5 1] (position-column [1 1 1] [c-wan c-wan c-wan] key))
      (translate-u [6 1] (position-column [2] [c-rcj] key))
      (translate-u [5.5 0.5] (key 2 1 c-rcj)))))

(def key-preview (position-keys keycap-area))

(def keyplate
  (difference
    (union (hull (position-keys key-area))
           (square (* key-spacing 2) (* key-spacing 2) :center false))
    (position-keys keyswitch-hole)))
(spit "scad/keyplate.scad" (scad/write-scad keyplate))
(spit "scad/keyplate-preview.scad" (scad/write-scad key-preview))
