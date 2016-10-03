# Problem Statement

<https://www.hackerrank.com/challenges/bigger-is-greater>

# Solution (`O(n*log(n))`)

1. Traverse the string (list of characters) from the end
2. Find first instance where `i`th character is lexicographically greater than the character to its left (`(i-1)`th)
3. Find the character from the `i`th index to the end, that is the next lexicographically greater character after the `(i-1)`th character
4. Swap those characters
5. Sort the characters of the string to the right of `(i-1)`th index

## Example

Given the string

    dhkc

We traverse from the back until we find an instance where a character is lexicographically greater than the one to its left:

    dkhc
       ^ !(c > h)
      ^  !(h > k)
     ^    (k > d)

Now that we found it, we have to find the character in the substring `khc` that is the first lexicographically greater character after `d`, which would be `h`. This traversal sub-operation performs with a worst-case runtime of `O(n)`.

Of course, to do so, we will sort the substring and traverse the sorted substring to find that character. The worst-case runtime for this sub-operation would be `O(n*log(n) + n) = O(n*log(n))`:

    d + sorted(khc) = dchk

Now that we find that `h` is the next greatest character in line, we swap them:

    dchk -> hcdk

Then sort the substring right of `h` again (worst-case runtime being `O(n*log(n))`):

    h + sorted(cdk) = hcdk

Hence, given a string of `n` characters, the worst-case runtime for this algorithm would be:

    O((n-1) + (n-1) * log(n-1) + (n-1) + (n-1)*log(n-1))

     = O(2n - 2 + (2n - 2) * log(n-1))

     = O(2 * (n - 1 + n*log(n-1) - log(n-1)))

    ~= O(n*log(n))
