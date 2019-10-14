(define (inner-my-assoc n cnt l)
  (if (= n cnt)
      (if (null? l)
	  "f"
	  (car l))
      (inner-my-assoc n (+ cnt 1) (cdr l))))
(define (my-assoc n l)
  (inner-my-assoc n 1 l))
