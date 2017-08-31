(define call/cc call-with-current-continuation)

;; Reduce/multiplication
(define multiply
  (lambda (l)
    (let ((halt (call/cc (lambda (k) k))))
      (if (procedure? halt)
          (letrec
            ((looper (lambda (current-list reduction)
               (if (or (null? current-list) (eq? (car current-list) 0))
                   (halt reduction)
                   (looper (cdr current-list) (* reduction (car current-list)))))))
            (looper l 1))
          halt))))

;; 120
(multiply `(1 2 3 4 5))

;; 24
(multiply `(1 2 3 4 0))