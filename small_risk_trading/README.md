# Problem Statement

<https://www.hackerrank.com/contests/moodysuniversityhackathon/challenges/small-risk-trading>

# Solution: `O (n log(n))`

1. Populate lists for profit probabilities and potential profits
2. Loop through potential losses
    * Calculate the expected money
    * If expected money is greater than 0, add to a list of expected money
3. Sort the list of expected money
    * If the size of the list is less than `k`, take the sum of the whole list
    * Otherwise take the sum of the last `k` elements of the list
