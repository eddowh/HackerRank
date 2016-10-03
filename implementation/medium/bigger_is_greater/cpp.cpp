/**
 * Bigger is Greater
 *
 * <https://www.hackerrank.com/challenges/bigger-is-greater>
 *
 * Author: Eddo W. Hintoso
 * E-mail: eddo.hintoso+github@gmail.com
 */

#include <iostream>
#include <algorithm>

int main(void)
{
    int t; // number of test cases
    std::string curr; // string provided

    std::cin >> t;
    while (t > 0) {
        std::cin >> curr;
        const int strlen = (int) curr.length();
        bool found = false; // is there a greater lexicograhically greater sequence?
        for (int i = strlen - 1; i >= 1; i--) {
            if (curr[i] > curr[i-1]) { // if char is greater than that to its left
                std::sort(curr.begin()+i, curr.end());
                // find the next lexicographically greater character to its right
                for (int j = i; j < strlen; j++) {
                    if (curr[j] > curr[i-1]) {
                        // swap the characters
                        char temp = curr[i-1];
                        curr[i-1] = curr[j];
                        curr[j] = temp;
                        break;
                    }
                }
                // sort characters to the right again, then print
                std::sort(curr.begin()+i, curr.end());
                std::cout << curr << std::endl;
                found = true;
                break;
            }
        }
        // no arrangements for a lexicographically greater string
        if (!found) {
            std::cout << "no answer" << std::endl;
        }
        t--;
    }

    return 0;
}
