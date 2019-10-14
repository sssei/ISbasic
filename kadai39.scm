(define (min-of-two a b)
  (if (< a b) a b))
(define (min-of-four a b c d)
  (if (< (min-of-two a b) (min-of-two c d))
      (min-of-two a b)
      (min-of-two c d)))
      
