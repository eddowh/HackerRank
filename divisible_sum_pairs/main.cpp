#include <iostream>

using namespace std;


int main(void)
{
    // init
    int n;
    int k;
    cin >> n >> k;
    int a[n];
    for (int a_i = 0; a_i < n; a_i++) {
        cin >> a[a_i];
    }

    // put into buckets of modulus
    int* mods = new int[k]();
    for (int i = 0; i < n; i++) {
        int m = a[i] % k;
        mods[m] += 1;
    }

    // sum of k-divisible pairs are always divisible by k
    // take combination of pairs
    int res = mods[0] * (mods[0] - 1) / 2;

    // pair combinations of (x % k) + (y % k) = k
    int range = (k + 1) / 2;
    for (int i = 1; i < range; i++) {
        res += mods[i] * mods[k-i];
    }

    // account for k/2 if it is even
    if (k % 2 == 0) {
        res += mods[k/2] * (mods[k/2] - 1) / 2;
    }

    cout << res << endl;

    delete [] mods;
    return 0;
}
