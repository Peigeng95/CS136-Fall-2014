;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Name: 
;; Student ID:
;; File: mathfunc.rkt 
;; CS 136 Fall 2014 - Assignment 2, Problem 5
;; Description: A set of math functions. 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

#lang racket

(provide max2 min2 maxfactor coprime )

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; max2 : Int Int -> Int
;;  PRE: true
;;  POST: produce an Int is the maximum of two
;; Purpose: produce the maximum value between integers a and b


;; min2 : Int Int -> Int 
;;  PRE: true
;;  POST: Produce an Int is the minimum of two.
;; Purpose: produce the minimum value between integers a and b


;; maxfactor : Int Int -> Int
;;  PRE: true
;;  POST: produce int >= 1
;; Purpose: produce the largest factor of an integer a, where a is 2
;;          or greater


;; coprime : Int Int -> Bool
;;  PRE: a>0 b>0
;;  POST: produce boolean
;; Purpose:  produce true if positive integers a and b are coprime,
;;           and false otherwise.

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; See interface above.
(define (max2 a b)
  (cond
    [(>= a b) a]
    [else b]))

;; See interface above.
(define (min2 a b)
  (cond
    [(<= a b) a]
    [else b]))

;; See interface above.
(define (maxfactor a)
  (local [(define (helper a b)
            (cond
              [(= (remainder a b) 0)(quotient a b)]
              [else (helper a (add1 b))]))]
    (helper a 2)))
;; See interface above.
(define (coprime a b) 
  (cond
    [(and (= (maxfactor a) 1) (= (maxfactor b) 1)) #t]
    [(= (remainder (max2 a b)(min2 a b))0) #f]
    [(> a b)(cond
              [(coprime b(quotient a (maxfactor a))) (coprime b(maxfactor a) )]
              [else #f])]
    [(< a b) (cond
              [(coprime a(quotient b (maxfactor b)))(coprime  (maxfactor b)a)]
              [else #f])]
    [else #f]))
