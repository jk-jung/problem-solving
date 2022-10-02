#include <cstring>
#include <cstdio>
#include <cmath>
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
    int n;
    cin >> n;
    vi v(n), r(n), used(n);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    r[0] = v[0];
    used[0] = 1;
    int g = r[0];
    for (int i = 1; i < n; i++) {
        int tmp = 0, idx = 0;
        for (int k = 0; k < n; k++) {
            if (!used[k] && gcd(g, v[k]) > tmp) {
                tmp = gcd(g, v[k]);
                idx = k;
            }
        }
        used[idx] = 1;
        r[i] = v[idx];

        g = tmp;
    }

    for (int x: r)cout << x << " ";
    cout << endl;
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
