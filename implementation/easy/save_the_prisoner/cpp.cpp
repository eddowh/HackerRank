/**
 * Save the Prisoner!
 *
 * <https://www.hackerrank.com/challenges/save-the-prisoner>
 *
 * Author: Eddo W. Hintoso
 * E-mail: eddo.hintoso+github@gmail.com
 */

#include <iostream>

int main(void)
{
    int t; // number of test cases
    long int n, m, s; // number of prionsers, sweets, and prisoner ID (respectively)

    std::cin >> t;
    for (int t_0 = 0; t_0 < t; t_0++) {
        std::cin >> n >> m >> s;
        long int poisoned_s = (s + m - 1) % n;
        std::cout << ((poisoned_s == 0) ? n : poisoned_s) << std::endl;
    }

    return 0;
}
