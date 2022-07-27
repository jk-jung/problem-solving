#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <set>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

void solve() {
    int n, t;
    string s;
    cin >> n >> t >> s;
    map<int, int> bal;

    int ck = t < 0 ? -1 : 1, c = 0;
    t *= ck;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') c += ck;
        else c -= ck;
        bal[c]++;
    }
    int L = bal.begin()->F;
    int R = bal.rbegin()->F;
    if (c == 0) {
        if (L <= t && t <= R) {
            cout << -1 << endl;
        } else cout << 0 << endl;
        return;
    }
    int base = 0;
    int r = t == 0 ? 1 : 0;
    if (L <= t && t <= R);
    else {
        if (c < 0) {
            cout << r << endl;
            return;
        }
        int k = (t - R + c - 1) / c;
        if (k < 0) k = 0;
        base = k * c;
    }

    while (base + L <= t && t <= base + R) {
        int need = t - base;
        if (bal.count(need))
            r += bal[need];
        base += c;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
