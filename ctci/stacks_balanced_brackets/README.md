# Problem Statement

<https://www.hackerrank.com/challenges/ctci-balanced-brackets>

# Solution: `O(n)`

Let there be a stack of characters.

Given each string expression with `n` characters, loop through each character:
* If it's any of the open brackets (`{, [, (`):
    * Push to stack
* If it's any of the closing brackets (`}, ], )`):
    * Return __unmatched__ if stack is empty
    * Check top of the stack and pop it if it matches
* Return __unmatched__ if stack is not empty after loop
* Otherwise return __matched__
