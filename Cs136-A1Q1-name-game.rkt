#lang racket
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Name: Peigeng Han
;; Student ID:20533982
;; File: hello.rkt
;; CS 136 Fall 2014 - Assignment 1, Problem 0
;; Description: that uses printf to display
;;              What is your first name?
;;              and then uses (read) to read in a first name
;;              from the keyboard.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define fname (read))

(define (new-name fname)
  (cond
    [(or (equal? (first (string->list (symbol->string fname))) #\a)
         (equal? (first (string->list (symbol->string fname))) #\e)
         (equal? (first (string->list (symbol->string fname))) #\i)
         (equal? (first (string->list (symbol->string fname))) #\o)
         (equal? (first (string->list (symbol->string fname))) #\u))
     fname]
    [else (list->string (rest (string->list (symbol->string  fname))))]))
(define nname (new-name fname))
(printf "What is your first name?")
(printf "~a, ~a, bo-b~a,\nbanana-fana fo-f~a\nfee-fi-mo-m~a\n~a!\n" fname fname nname nname nname fname)