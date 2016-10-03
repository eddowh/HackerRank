/**
 * Absolute Permutation
 *
 * <https://www.hackerrank.com/challenges/absolute-permutation>
 *
 * Author: Eddo W. Hintoso
 * E-mail: eddo.hintoso+github@gmail.com
 */

#include <iostream>

int main(void)
{
    int t; // number of test cases;
    int n, k;

    std::cin >> t;
    for (int t_i = 0; t_i < t; t_i++) {
        std::cin >> n >> k;

        if (k == 0) {
            for (int i = 0; i < n; i++) {
                std::cout << i+1 << " " << std::flush;
            }
            std::cout << std::endl;
            continue;
        }
        // n has to be divisible by k
        else if ((n % k) != 0) {
            std::cout << -1 << std::endl;
        }
        else if ((n / k) % 2 != 0) {
            std::cout << -1 << std::endl;
        }
        else {
            // guaranteed to find absolute permutation
            int ctr = k;
            for (int i = 1; i <= n; i++) {
                if (ctr <= -k) {
                    ctr = k;
                }
                ctr--;
                std::cout << ((ctr < 0) ? i-k : i+k) << " " << std::flush;
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
