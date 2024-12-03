#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<pair<int, string>> r;
    for (char x = '0'; x <= '9'; x++) {
        string t = s;
        int val = 0;
        int need = k;
        for (char y: s)need -= y == x;
        for (int d = 1; d <= 9; d++) {
            char c = x + d;
            if (c <= '9') {
                for (int i = 0; i < n; i++) {
                    if (need > 0 && t[i] == c) {
                        t[i] = x;
                        need--;
                        val += d;
                    }
                }
            }
            c = x - d;
            if (c >= '0') {
                for (int i = n - 1; i >= 0; i--) {
                    if (need > 0 && t[i] == c) {
                        t[i] = x;
                        need--;
                        val += d;
                    }
                }
            }

        }
        r.pb(mp(val, t));
    }
    sort(r.begin(), r.end());
    cout << r[0].F << endl;
    cout << r[0].S << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
