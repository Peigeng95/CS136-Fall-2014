;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Name: Peigeng Han
;; Student ID: 20533982
;; File: simon.rkt 
;; CS 136 Fall 2014 - Assignment 1, Problem 3
;; Description: Plays the Simon game! 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

#lang racket

(provide simon-round-lists)

;; simon-round-lists : List Int -> List
;;    PRE: (length lst) >= Int
;;    POST: List
;; Purpose: provided colour list to create lists of colours 
;;          for each round of the Simon game upto and including 
;;          the provided natural number and produce a list of all colour lists

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;see interface above
(define (simon-round-lists col-list rounds)
  (reverse (simon-round-lists-almost col-list rounds)))

;;simon-round-lists-almost: List Int -> List
;; provide the list but with reverse order
(define (simon-round-lists-almost col-list rounds)
  (cond
    [(equal? 0 rounds) empty]
    [else (cons (simon-round-lists-helper col-list rounds)
                (simon-round-lists-almost col-list (sub1 rounds)))]))

;;simon-round-lists-helper: List Int -> List
;;provide the sub-list in the main list
(define (simon-round-lists-helper col-list rounds)
  (cond
    [(= 0 rounds) empty]
    [else (cons (first col-list) (simon-round-lists-helper (rest col-list) (sub1 rounds)))]))
