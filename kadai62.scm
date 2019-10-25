(define (btree-empty)
  ;; 空木を返す。
  (list))
(define (btree-null? t)
  ;; 二分木`t'が空かどうかを真偽値で返す。
  (equal? t (list)))

(define btree-root cadr)
(define btree-left car)
(define btree-right caddr)

(define (btree-insert key val t)
  ;; 文字列`key'をキーとして文字列`val'を二分探索木`t'に挿入し、その木を返す。
  (cond ((btree-null? t) (list (list) (cons key val) (list)))
	((string<? (car (btree-root t)) key)
	 (list (btree-left t) (btree-root t) (btree-insert key val (btree-right t))))
	((string>? (car (btree-root t)) key)
	 (list (btree-insert key val (btree-left t)) (btree-root t) (btree-right t)))
	((string=? (car (btree-root t)) key)
	 (list (btree-left t) (cons (car (btree-root t)) val) (btree-right t)))))


(define (btree-delete key t)
  ;; 文字列`key'をキーとする項目を、二分探索木`t'から削除し、その木を返す。
  (define (btree-min-delete t)
    (if (btree-null? (btree-left t))
  	(btree-right t)
  	(list (btree-min-delete (btree-left t)) (btree-root t) (btree-right t))))
  (define (btree-min t)
    (if (btree-null? (btree-left t))
	(btree-root t)
	(btree-min (btree-left t))))
  (cond ((btree-null? t) (btree-empty))
	((string<? (car (btree-root t)) key)
	 (list (btree-left t) (btree-root t) (btree-delete key (btree-right t))))
	((string>? (car (btree-root t)) key)
	 (list (btree-delete key (btree-left t)) (btree-root t) (btree-right t)))
	(else
	 (cond ((and (btree-null? (btree-left t)) (btree-null? (btree-right t))) (btree-empty))
	       ((btree-null? (btree-left t)) (btree-right t))
	       ((btree-null? (btree-right t)) (btree-left t))
	       (else (list (btree-left t) (btree-min (btree-right t)) (btree-min-delete (btree-right t))))))))

(define (btree-search key t)
  ;; 文字列`key'をキーとして二分探索木`t'を検索し、キーとデータのペアを返す。
  ;; 見つからない場合は、#fを返す。
  (cond ((btree-null? t) #f)
	((string<? (car (btree-root t)) key) (btree-search key (btree-right t)))
	((string>? (car (btree-root t)) key) (btree-search key (btree-left t)))
	((string=? (car (btree-root t)) key) (btree-root t))))

