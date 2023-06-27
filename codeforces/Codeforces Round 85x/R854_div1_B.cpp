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
    set<int> s;
    for (int &x: v)cin >> x, s.insert(x);
    if (s.size() == 1) {
        cout << 0 << endl;
    } else if (*s.begin() == 1) {
        cout << "-1\n";
    } else {
        vector<pi> r;
        while (true) {
            int m = 0, M = 0;
            for (int i = 0; i < n; i++) {
                if (v[i] < v[m])m = i;
                if (v[i] > v[M])M = i;
            }
            if (v[m] == v[M])break;
            for (int i = 0; i < n; i++) {
                if (v[i] != v[m]) {
                    r.pb({i + 1, m + 1});
                    v[i] = (v[i] + v[m] - 1) / v[m];
                }
            }
        }
        cout << r.size() << endl;
        for (auto [x, y]: r) {
            cout << x << " " << y << endl;
        }
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
