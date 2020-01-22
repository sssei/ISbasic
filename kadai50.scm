(define (my-assoc key l)
  (cond ((null? l) #f)
	((equal? key (car (car l))) (car l))
	(else (my-assoc key (cdr l)))))


