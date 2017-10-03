# -*- coding: utf-8 -*-

"""
Stacks: Balanced Brackets
<https://www.hackerrank.com/challenges/ctci-balanced-brackets>

    Author: Eddo W. Hintoso
    E-mail: eddo.hintoso+github@gmail.com
"""

RHS = set([']', '}', ')'])

LHS_MAPPED_TO_RHS = {
    '[': ']',
    '(': ')',
    '{': '}',
}


def is_matched(expression):
    # if it is not even length, obviously not match
    if len(expression) % 2 != 0:
        return False
    # create new list as stack
    expr_stack = []
    for char in expression:
        if char in RHS:
            if len(expr_stack) == 0:
                return False
            if char == LHS_MAPPED_TO_RHS[expr_stack[-1]]:
                expr_stack.pop()
            else:
                return False
        else:
            expr_stack.append(char)
    # if stack is empty, it's balanced
    return len(expr_stack) == 0


t = int(input().strip())
for a0 in range(t):
    expression = input().strip()
    if is_matched(expression) == True:
        print("YES")
    else:
        print("NO")
