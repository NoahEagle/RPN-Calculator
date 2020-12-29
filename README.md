# RPN-Calculator
Implements an RPN calculator (where instead of 7 * 3, you'd do 3 7 * ) using a stack. 

The following operations are available: addition, subtraction, multiplication, division, 
swapping top two, removing top, duplicating top, and clearing all.

To actually run the RPN calculator, download all the files and then run the makefile by running the command line "make all".

It'll create an executable called "rpn", which you can then run via "./rpn"

***For subtraction, pushing 5 then 3 then - --> (5 3 -) is the same as 5 - 3 (subtraction takes the top of the stack and subtracts it from the 2nd element)

***For division, pushing 5 then 3 then / --> (5 3 /) is the same as 5 / 3 (division takes the 2nd element and divides it by the top of the stack)

***Whenever you do some mathematical operation (add, sub, mul, div), the two involved numbers are removed from the stack and the result of the operation is put on top

***When inputting to the calculator, you have to do one "thing" at a time. You can't input 5 3 + to do 5 + 3, you'd have to input 5 then 3 then +
