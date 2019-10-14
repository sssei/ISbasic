(define (reverse_list l r) 
  (if (null? l)
      r
      (reverse_list (cdr l) (cons (car l) r))))
(define (my-reverse l) 
  (reverse_list l (list)))
