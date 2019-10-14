(define (sum-total l)
  (define (inner-sum-total l init)
    (if (null? l)
	init
	(inner-sum-total (cdr l) (+ init (car l)))))
  (inner-sum-total l 0))
