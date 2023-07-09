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
    vi v(n);
    for (int &x: v)cin >> x;
    int t = v[0];
    for (int x: v)t &= x;

    if (t) cout << 1 << endl;
    else {
        int r = 0;
        vi q(n + 1);
        q[n - 1] = v.back();
        for (int i = n - 2; i >= 0; i--)q[i] = v[i] & q[i + 1];
        v.pb(0);
        for (int i = 0, s = v[0]; i < n; i++) {
            s &= v[i];
            if (s == 0 && q[i + 1] == 0)r++, s = v[i + 1];
        }
        cout << r << endl;
    }

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
