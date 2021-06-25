#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back

int a[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)cin >> a[i];
        sort(a, a + n);
        ll r = 0;
        for (int i = 1; i < n; i++) {
            r -= (ll) (a[i] - a[i - 1]) * ((ll) (i) * (ll) (n - i) - 1);
        }
        cout << r << endl;
    }
}
