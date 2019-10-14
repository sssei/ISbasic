(define (sieve-iter m i f)
  (cond ((< i 2) (sieve-iter m 2 f))
        ((< m i) f)
        ((f i)
	 (sieve-iter m (+ i 1) (lambda (n)
				 (and (f n) (< 0 (modulo n i)))))) (else (sieve-iter m (+ i 1) f))))

(define (sieve2 m)
  (sieve-iter m 2 (lambda (n) #t)))

(define (sieve cnt m l)
  (cond ((> cnt m) l)
	(((sieve2 (- cnt 1)) cnt)
	 (sieve (+ cnt 1) m (cons cnt l)))
	(else (sieve (+ cnt 1) m l))))

(define (sieve3 m)
  (sieve 2 m (list)))

