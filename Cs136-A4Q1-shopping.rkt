;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Name: Peigeng Han
;; Student ID: 20533982
;; File: shopping.rkt 
;; CS 136 Fall 2014 - Assignment 4, Problem 1
;; Description: A shopping list! 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

#lang racket

(provide 
  create-shopping
  destroy-shopping
  shopping-add
  shopping-remove
  shopping-clear
  shopping-list)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;IMPLEMENTATION;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; create-shopping : void 
;; PRE: void
;; POST: display "shopping list created" if no shopping list exist. distplay "error: shopping list already exists" otherwise
;; Purpose: creates a shopping list if one does not already exist.

;; destroy-shopping : void
;; PRE: true
;; POST: display "shopping list with X item(s) destroyed" if shopping list exist. distplay "error: no shopping list exists" otherwise.
;; Purpose: destroys a shopping list 

;; shopping-add : String -> Void
;; PRE: true
;; POST: display "added: S" if shopping list does not contain the string. distplay "already in list: S" otherwise.
;; Purpose:adds the item s to the shopping list

;; shopping-remove : String -> Void
;; PRE: true
;; POST: display "remove: S" if shopping list contain the string. distplay "not in list: S" otherwise.
;; Purpose: removes the item s from the shopping list

;; shopping-clear : Void
;; PRE: Void
;; POST: display "shopping list cleared"
;; Purpose:removes all items from the shopping list

;; shopping-list : Void
;; PRE: true
;; POST: sort the list in alphabetical order
;; Purpose:produces the shopping list in alphabetical order 

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;shopping list
(define shopping-list1 '("null"))

;; see interface above
(define (create-shopping) 
  (if (equal? shopping-list1 '("null"))
      (begin
        (printf "shopping list created\n")
        (set! shopping-list1 empty))
      (printf "error: shopping list already exists\n")))


;; see interface above
(define (destroy-shopping) 
  (if (equal? shopping-list1 '("null"))
      (printf "error: no shopping list exists\n")
      (printf "shopping list with ~a item(s) destroyed\n" (length shopping-list1))
       )
  (set! shopping-list1 '("null")))

;; see interface above
(define (shopping-add s)
  (if (equal? shopping-list1 '("null")) 
      (printf "error: no shopping list exists\n")
      (if (member s shopping-list1)
           (printf "already in list: ~a\n" s)
           (begin
             (printf "added: ~a\n" s)
             (set! shopping-list1 (cons s shopping-list1))))))

;; see interface above
(define (shopping-remove s)
  (if (equal? shopping-list1 '("null")) 
      (printf "error: no shopping list exists\n")
      (if (member s shopping-list1)
          (begin
            (printf "removed: ~a\n" s)
            (set! shopping-list1 ((lambda (x) 
                                   (filter (lambda (x) 
                                             (not (equal? s x))) x))
                                 shopping-list1)))
          (printf "not in list: ~a\n" s))))


;; see interface above
(define (shopping-clear) 
  (if (equal? shopping-list1 '("null")) 
      (printf "error: no shopping list exists\n")
      (begin
        (printf "shopping list cleared\n")
        (set! shopping-list1 empty))))

;; see interface above

(define (shopping-list) 
  (sort shopping-list1 string<?))
