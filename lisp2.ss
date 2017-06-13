;  half-interval.ss

(define (good temp)
  (display "[good]")
  temp
)
(define (bad temp)
  (display "[bad]")
  temp
)

(define (tolerance) (define value 0.00001) value)

(define (half-interval-metod a b)
  (define a-value 0)
  (define b-value 0)
  (set! a-value (fun a))
  (set! b-value (fun b))
  (cond((and(and (<= a-value 0) (not (and (<= a-value 0) (<= 0 a-value)))) (not (<= b-value 0)))
              (try a b))
      (#t (cond
        ((and(not (<= a-value 0)) (and (<= b-value 0) (not (and (<= b-value 0) (<= 0 b-value)))))
                (try b a))
        (#t (+ b 1))
      ))
  )
)
(define(try neg-point pos-point)
  (define midpoint 0)
  (define test-value 0)
  (set! midpoint (average neg-point pos-point))
  (display "+")
  (cond((close-enough? neg-point pos-point) midpoint)
       (#t (set! test-value (fun midpoint))
           (cond((not (<= test-value 0))(try neg-point midpoint))
                (#t (cond
                  ((and (<= test-value 0) (not (and (<= test-value 0) (<= 0 test-value))))(try midpoint pos-point))
                  (#t midpoint))
                ))
           )
  )
  )

(define (close-enough? x y)
  (and (<= (abs (- x y)) (tolerance)) (not (and (<= (abs (- x y)) (tolerance)) (<= (tolerance) (abs (- x y)))))))
(define (average x y)(/(+ x y)2.))
(define (root a b)
  (define temp 0)
  (set! temp(half-interval-metod a b))
  (newline)
  (display "interval=\t[")
  (display a)
  (display " , ")
  (display b)
  (display "]\n")
  (display "discrepancy=\t")
  (display (fun temp))
  (newline)
  (display "root=\t\t")
  (define dump 0)
  (set! dump (cond ((and (<= (- temp b 1) 0) (<= 0 (- temp b 1))) (bad temp))
    (#t (good temp))))
  temp
)
(define(fun z)
  (set! z (- z (/ 34 35)(/ 1 pi)))
;=========================================================
;C++: z + sin z + cos z = 0
;=========================================================
  (+(+ z (sin z)) (cos z))
)

" SPA variant 34"
(root 0 1)
