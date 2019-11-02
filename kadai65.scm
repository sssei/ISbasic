(define (reverse_list l r) ;rにlを追加
  (if (null? l)
      r
      (reverse_list (cdr l) (cons (car l) r))))

(define (reverse2 l) ;lをreverseする
  (reverse_list l (list)))

(define (append-list l r) ;lとrを結合
  (reverse_list (reverse2 l) r))

(define (my-list l r min) ;minを先頭にしたリストを戻す
  (cond ((null? l) (cons min r))
	((string<? (car l) min) (my-list (cdr l) (cons min r) (car l)))
	(else (my-list (cdr l) (cons (car l) r) min))))

(define (inner-bubble l) ;最小値を先頭にしたリストを戻す
  (my-list (cdr l) (list) (car l)))

(define (bubble-sort l r)
  (if (null? r)
      l
      (bubble-sort (append-list l (list (car (inner-bubble r)))) (cdr (inner-bubble r)))))

(define (my-sort l)
  (bubble-sort (list) l))




