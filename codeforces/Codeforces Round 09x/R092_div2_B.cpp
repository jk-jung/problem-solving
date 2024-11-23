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
    cin >> n >> k;
    vi v(k);
    vector<string> s(n);
    for (auto &x: s)cin >> x;
    for (int i = 0; i < k; i++)v[i] = i;
    int r = 1 << 30;
    do {
        vi t;
        for (auto &x: s) {
            int q = 0;
            for (int i: v) q = q * 10 + x[i] - '0';
            t.pb(q);
        }
        sort(t.begin(), t.end());
        r = min(r, t.back() - t[0]);
    } while (next_permutation(v.begin(), v.end()));
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
