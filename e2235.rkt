
;; 玩一下 Racket XD

(define/contract (sum num1 num2)
  (-> exact-integer? exact-integer? exact-integer?)
    (+ num1 num2)
  )


;; Runtime: 202 ms, faster than 95.24% of Racket online submissions for Add Two Integers.
;; Memory Usage: 98.6 MB, less than 28.57% of Racket online submissions for Add Two Integers.
