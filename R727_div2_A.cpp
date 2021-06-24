#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll k, n, x, t;
    ll r;
    cin >> k;

    while (k--) {
        scanf("%lld%lld%lld", &n, &x, &t);
        ll c = t / x;

        if (c + 1 > n) {
            r = n * (n - 1) / 2;
        }
        else {
            r = c * (c + 1) / 2;
            r += c * (n - c - 1);
        }

        cout << r << endl;
    }
    return 0;
}
