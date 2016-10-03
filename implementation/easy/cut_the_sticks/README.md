# Problem Statement

<https://www.hackerrank.com/challenges/cut-the-sticks>

# Solution (`O(n*log(n))`)

1. Sort the list (mergesort takes `O(n*log(n))`).
2. Traverse through the list, while keeping track of minimum numbers and size counter
    * If element is greater than minimum, set minimum to that element and print out size counter

## Example

Given the sticks

    1 2 3 4 3 3 2 1

Sort them

    1 1 2 2 3 3 3 4

Print out `n` (number of sticks) since it is guaranteed that all sticks will be cut first.

Set minimum to first element of list (since it is sorted).

    minlen = 1

Loop through the list until it hits a number greater than the current minimum, `1`. Reset the current minimum to that value.

    1 1 2 2 3 3 3 4
        ^

By then we know that two of the sticks have been reduced to size 0, and we only have `n-2` sticks left guaranteed to be cut. We accordingly print the value of `n-2` out.

We continue looping through the list and do the same if we hit a different number (guaranteed to be greater in a sorted list):

    1 1 2 2 3 3 3 4
            ^

Using the same logic established before, we print the value of `n-4`. Notice that if we are accessing the elements of the list using an index `i`, `3` is at index `4`.

By the time we reach `4`, which is the maximum number in the list, we print out the value of `n-(n-1)`, which is simply `1`.

Hence we print out:

    n
    n - 2
    n - 4
    n - (n + 1)

Which is equivalent to:

    8
    6
    4
    1
