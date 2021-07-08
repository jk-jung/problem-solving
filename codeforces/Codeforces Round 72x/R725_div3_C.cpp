#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back


ll calc(vector<int> &v, int t) {
    ll r = 0;
    for (int i = 0; i < v.size(); i++) {
        int k = upper_bound(v.begin(), v.end(), t - v[i]) - v.begin();
        r += k;
        if (k - 1 >= i) r --;
    }
    return r / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, l, r;
    cin >> t;
    while (t--) {
        cin >> n >> l >> r;
        vector<int> v(n);
        for (int i = 0; i < n; i++)cin >> v[i];
        sort(v.begin(), v.end());

        cout << calc(v, r) - calc(v, l - 1) << endl;
    }
}
