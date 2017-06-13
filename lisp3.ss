(define (cc amount largest-coin)
  (cond ((not (and (not (and (<= amount 0) (<= 0 amount))) (not (and (<= largest-coin 1) (<= 1 largest-coin))))) 1)
  	(#t (cond
  ((not(and (not(<= amount 0)) (not (<= largest-coin 0)))) 0)
  (#t (+ (cc amount (next-coin largest-coin)) (cc (- amount largest-coin) largest-coin)))))))


(define (count-change amount)
	(cc amount (LAGEST-COIN)))


(define (next-coin coin)
	(cond ((and (<= coin 25) (<= 25 coin)) 15)
		(#t (cond
			((and (<= coin 15) (<= 15 coin)) 5)
			(#t (cond
				((and (<= coin 5) (<= 5 coin)) 2)
				(#t 0)))))))

(define (GR-AMOUNT)
	(* 10 (LAST-DIGIT-OF-GROUP-NUMBER)))

(define (LAGEST-COIN) (define value 25) value)
(define (LAST-DIGIT-OF-GROUP-NUMBER) (define value 8) value)

(display " SPA variant 17")
(newline)
(display " 2-5-15-25")
(newline)
(display "count__change for 100 \t= ")
(display (count-change 100))
(newline)
(display "count__change for ")
(display (GR-AMOUNT))
(display " \t= ")
(display (count-change (GR-AMOUNT)))
