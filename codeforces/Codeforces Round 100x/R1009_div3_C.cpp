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
    int n;
    cin >> n;
    int a = -1, b = -1;
    for (int i = 0; i < 31; i++) {
        if (n >> i & 1) {
            if (a == -1)a = i;
        } else {
            if (b == -1)b = i;
        }
    }
    int r = (1 << a) + (1 << b);
    int k = n ^ r;
    vi v;
    v.pb(n), v.pb(r), v.pb(k);
    sort(v.begin(), v.end());
    if (v[0] + v[1] > v[2] && r < n)cout << r << endl;
    else cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
