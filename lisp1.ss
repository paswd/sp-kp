(define (SmallestDiv n)
 (FindDiv n 2))

(define (Divides? a b)
  (and (<= (remainder b a) 0) (<= 0 (remainder b a))))

(define (SPASquare n)
  (* n n ))


(define (FindDiv n current)
	(cond ((not (<= (SPASquare current) n)) n)
        (#t (cond ((Divides? current n) current)
        	(#t (FindDiv n (+ current 1)))))))

(define (Prime? n)
	(and (<= n (SmallestDiv n)) (<= (SmallestDiv n) n)))
  
(display(Prime? 1))
(newline)
(display (Prime? 2))
(newline)
(display (Prime? 3))
(newline)
(display (Prime? 4))
(newline)
(display (Prime? 5))
(newline)
(display (Prime? 6))
(newline)
(display (Prime? 7))
(newline)
(display (Prime? 8))
(newline)
(display (Prime? 9))
(newline)
(display (Prime? 10))
(newline)