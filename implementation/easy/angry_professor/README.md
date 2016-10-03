# Problem Statement

<https://www.hackerrank.com/challenges/angry-professor>

# Solution

In a C++11 implementation, there is no need to use lists.

Simply compare whether the arrival times are nonpositive and if they are, reduce the `k` counter.

If `k < 0` that means the minimum threshold of attendance is met.
