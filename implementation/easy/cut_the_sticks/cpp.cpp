/**
 * Cut the sticks
 *
 * <https://www.hackerrank.com/challenges/cut-the-sticks>
 *
 * Author: Eddo W. Hintoso
 * E-mail: eddo.hintoso+github@gmail.com
 */

#include <algorithm>
#include <iostream>

int main(void)
{
    int n; // number of sticks
    int minlen;

    std::cin >> n;
    int* arr = new int[n];
    for (int arr_i = 0; arr_i < n; arr_i++) {
        std::cin >> arr[arr_i];
    }

    // sort the array
    std::sort(arr, arr+n);
    int sticks_ctr = n;
    minlen = arr[0];

    // everytime the value changes
    // (meaning all the minimum length so far has been removed)
    // print the counter which keeps track of vector size
    std::cout << sticks_ctr << std::endl;
    for (int i = 0; i < n; i++) {
        if (minlen != arr[i]) {
            minlen = arr[i];
            std::cout << sticks_ctr << std::endl;
        }
        sticks_ctr--;
    }

    delete [] arr;
    return 0;
}
