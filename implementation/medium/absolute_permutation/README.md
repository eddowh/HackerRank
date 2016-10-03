# Problem Statement

<https://www.hackerrank.com/challenges/absolute-permutation>

# Solution (`Theta(n)`)

There are three conditions that must be met for an absolute permutation to be possible:

1. `n` has to be divisible by `k` (`n mod k == 0`)
2. `n/k` has to divisible by 2 (`(n / k) mod 2 == 0`)

These will be demonstrated with examples.

## `n = 12, k = 5`

    1  2  3  4  5  6  7  8  9  10 11 12
    6  7  8  9  10 1  2  3  4  5  11 12
    -----------------------------------
    5  5  5  5  5  5  5  5  5  5  0  0

Notice how we're swapping each number with another number less than or equal to `k` that will have a difference of `k`. If `n` is not divisible by `k`, there are simply not enough numbers to swap in order to satisfy the conditions of absolute permutation.

## `n = 12, k = 4`

    1  2  3  4  5  6  7  8  9  10 11 12
    5  6  7  8  1  2  3  4  13 14 15 16
    -----------------------------------
    4  4  4  4  4  4  4  4  4  4  4  4

Notice how the last four numbers don't have a match. They could be paired up with the numbers less than themselves (i.e. `9` with `5`), except the smaller numbers have already been taken.

Despite the fact that `n` is divisible by `k`, `n / k` is not divisible by 2, hence not satisfying the condition.

## `n = 12, k = 3`

    1  2  3  4  5  6  7  8  9  10 11 12
    4  5  6  1  2  3  10 11 12 7  8  9
    -----------------------------------
    3  3  3  3  3  3  3  3  3  3  3  3

Notice how we swap in pairs of 3 (1 - 6, 7 - 12) at one time:

    1 2 3 4 5 6 | 7  8  9 10 11 12
    4 5 6 1 2 3 | 10 11 12 7  8  9

That is why it has to be the case that `n / k` must be divisible by `2`.

After establishing whether or not the given parameters satisfy the conditions for an absolute permutation, it's only a matter of manipulating additions and array indexes to print out the correct output, which would have a runtime of `Theta(n)`.
