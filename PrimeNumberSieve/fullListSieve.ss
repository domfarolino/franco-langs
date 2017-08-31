;; Full list version of the prime number sieve in Scheme. This example does not use lambda to delay any
;; computation, therefore the implementation is rather memory inefficient and requires O(n) stack space
;; The next example will utilize a "stream" for a more efficient solution

;; Tail recursive function to create a list with elements from 2 to n
(define consecutive-list-helper
  (lambda (current n acc-list)
    (if (> current n)
        acc-list
        (consecutive-list-helper current (- n 1) (cons n acc-list)))))

(define consecutive-list
  (lambda (begin end) (consecutive-list-helper begin end `())))

;; Recursively computes a list with all multiples of n filtered out from some input list
(define elim-mults
  (lambda (list n)
    (if (eq? list `())
        `()
        (if (eq? (modulo (car list) n) 0)
            (elim-mults (cdr list) n)
            (cons (car list) (elim-mults (cdr list) n))))))

;; Recursively computes a list of all primes under n where n is the last number of the original input list
;; This is done by recursively calling elim-mults on the current state of the input list
;; Try it like this: `(all-primes (consecutive-list 2 800))`
(define all-primes
  (lambda (list)
    (if (eq? list `())
        `()
        (cons (car list) (all-primes (elim-mults list (car list)))))))