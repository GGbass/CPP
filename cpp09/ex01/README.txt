1. The Theory: What is RPN?
Reverse Polish Notation (or Postfix notation) is a mathematical notation in which operators follow their numbers.

Infix (Normal): 3 + 4

RPN (Postfix): 3 4 +

Why use it? It eliminates the need for parentheses to define order of operations.
The computer simply processes the list from left to right.

2. The Best Container: std::stack
For this specific algorithm, the standard approach is to use a Stack. Since you haven't used it yet, 
std::stack is the perfect candidate for this exercise.

Why? The logic of RPN requires you to "remember" the most recent numbers you saw so that when you hit an operator (like + or *),
you can grab the last two numbers, calculate them, and put the result back.

How it works: You push numbers onto the top, and pop them off when you need to calculate.

3. The Algorithm Logic
Your program needs to process the input string token by token. Here is the logical flow you should implement:

Iterate through the input string (argument 1).

Check the character:

If it is a number (0-9): Convert it to an integer and push it onto the stack. Note: The subject says input numbers will always be less than 10, which simplifies parsing significantly.

*If it is an operator (+ - / ):

Check if the stack has at least 2 numbers. If not -> Error.

pop the top number (this is your right-hand operand).

pop the next number (this is your left-hand operand).

Perform the operation (e.g., Left - Right).

push the result back onto the stack.

If it is a space: Ignore/Skip.

Anything else: Error.

Final Result: Once you reach the end of the string, check the stack.

If there is exactly one number left, that is your result. Print it.

If the stack is empty or has multiple numbers left -> Error.

4. Critical Edge Cases to Handle
Division by Zero: If the operator is / and the right-hand operand is 0, you must throw an error.

Order of Operations: When popping for subtraction or division, 
remember that the first number you pop is the second number in the operation.

Example: 8 2 /

Stack: [8, 2] (2 is at the top).

Pop 2, then Pop 8.

Calculation: 8 / 2 (Correct), NOT 2 / 8 (Incorrect).


Negative Results: While input numbers are positive single digits, 
the result and intermediate calculations can be negative or larger than 10.

5. Implementation Strategy
Since you cannot use std::map, include <stack> in your header.



Approach  !!!!

2. The Best Container: std::stack

Why? The logic of RPN requires you to "remember" the most recent numbers you saw so that when you hit an operator (like + or *),
 you can grab the last two numbers, calculate them, and put the result back.

How it works: You push numbers onto the top, and pop them off when you need to calculate.

3. The Algorithm Logic
Your program needs to process the input string token by token. Here is the logical flow you should implement:

Iterate through the input string (argument 1).

Check the character:

If it is a number (0-9): Convert it to an integer and push it onto the stack. Note: 
The subject says input numbers will always be less than 10, which simplifies parsing significantly.

*If it is an operator (+ - / ):

Check if the stack has at least 2 numbers. If not -> Error.

pop the top number (this is your right-hand operand).

pop the next number (this is your left-hand operand).

Perform the operation (e.g., Left - Right).

push the result back onto the stack.

If it is a space: Ignore/Skip.

Anything else: Error.

Final Result: Once you reach the end of the string, check the stack.

If there is exactly one number left, that is your result. Print it.

If the stack is empty or has multiple numbers left -> Error.

4. Critical Edge Cases to Handle
Division by Zero: If the operator is / and the right-hand operand is 0, you must throw an error.

Order of Operations: When popping for subtraction or division, 
remember that the first number you pop is the second number in the operation.

Example: 8 2 /

Stack: [8, 2] (2 is at the top).

Pop 2, then Pop 8.

Calculation: 8 / 2 (Correct), NOT 2 / 8 (Incorrect).


Negative Results: While input numbers are positive single digits, 
the result and intermediate calculations can be negative or larger than 10.

5. Implementation Strategy
Since you cannot use std::map, include <stack> in your header.