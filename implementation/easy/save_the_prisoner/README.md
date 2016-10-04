# Problem Statement

<https://www.hackerrank.com/challenges/save-the-prisoner>

# Solution (`O(1)`)

Use modular arithmetic for a closed form solution.

If the reaminder isn't 0, the remainder would be the ID of the poisoned prisoner.

Else, the prisoner with the last ID (`n`) is the one poisoned.
