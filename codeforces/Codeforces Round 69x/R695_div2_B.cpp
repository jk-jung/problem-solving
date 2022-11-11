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


int cost(vi &v, int i) {
    if (i <= 0 || i >= v.size() - 1) return 0;
    if (v[i - 1] < v[i] && v[i] > v[i + 1]) return 1;
    if (v[i - 1] > v[i] && v[i] < v[i + 1]) return 1;
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    int s = 0;
    for (int i = 0; i < n; i++) s += cost(v, i);
    int r = s;
    for (int i = 0; i < n; i++) {
        vi val;
        if (i + 1 < n) val.pb(v[i + 1]);
        if (i > 0) val.pb(v[i - 1]);
        for (auto y: val) {
            int t = s;
            t -= cost(v, i - 1);
            t -= cost(v, i + 1);
            t -= cost(v, i);

            int x = v[i];
            v[i] = y;
            t += cost(v, i - 1);
            t += cost(v, i + 1);
            t += cost(v, i);
            v[i] = x;
            r = min(r, t);
        }
    }
    cout << r << endl;
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
