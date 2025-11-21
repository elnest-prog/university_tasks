(defun calc_fib (counter first_fib second_fib sum result_list)
  (cond
    ((= counter 0) (list sum (reverse result_list))) 
    (t (calc_fib 
                (- counter 1) 
                second_fib 
                (+ first_fib second_fib) 
                (+ sum second_fib)
                (cons second_fib result_list)))))

(defun sum_with_list (lst)
        (calc_fib (- (first lst) 1) 0 1 0 '(0)))

(print (sum_with_list '(12)))
