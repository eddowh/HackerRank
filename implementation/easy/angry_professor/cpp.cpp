/**
 * Angry Professor
 *
 * <https://www.hackerrank.com/challenges/angry-professor>
 *
 * Author: Eddo W. Hintoso
 * E-mail: eddo.hintoso+github@gmail.com
 */

#include <iostream>

int main(void)
{
    int t; // number of test cases
    int n; // number of students in the clas
    int k; // cancellation threshold

    std::cin >> t;
    for (int a0 = 0; a0 < t; a0++) {
        std::cin >> n >> k;
        int arrival;
        for (int _ = 0; _ < n; _++) {
            std::cin >> arrival;
            if (arrival <= 0) {
                k--;
            }
        }
        // if k is greater than 0 that means the threshold
        // hasn't been met
        std::cout << ((k > 0) ? "YES" : "NO") << std::endl;
    }

    return 0;
}
