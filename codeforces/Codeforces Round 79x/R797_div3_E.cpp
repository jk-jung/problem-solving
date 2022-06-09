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
    int n, k;
    cin >> n >> k;
    vector<vi> v(k);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        v[x % k].pb(x);
    }
    ll r = 0;

    for (int e = k - 1, s = 1; s <= e; e--) {
        while (!v[e].empty()) {
            while (v[s].empty() || s + e < k) s++;
            if (s > e || (s == e && v[e].size() < 2))break;
            int a = v[e].back();
            v[e].pop_back();
            int b = v[s].back();
            v[s].pop_back();
            r += (a + b) / k;
        }
    }
    for (int i = 0, last = -1; i < k; i++) {
        while (!v[i].empty()) {
            if (last == -1)last = v[i].back();
            else {
                r += (last + v[i].back()) / k;
                last = -1;
            }
            v[i].pop_back();
        }
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
