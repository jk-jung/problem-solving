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
    vi s(n + 1), e(n + 1);
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if (!s[x]) s[x] = i;
        e[x] = i;
    }
    vector<pair<pi, int>> v;
    for (int i = 1; i <= n; i++)if (s[i])v.pb({{e[i], s[i]}, i});
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int last = 1 << 30, r = 0;
    for (int i = 0; i < v.size(); i++) {
        auto [y, x] = v[i].F;
        int k = v[i].S;

        if (k > last) {
            r++;
            last = 0;
        } else if (i + 1 == v.size()) {
            last = k;
        } else {
            if (i + 1 < v.size()) {
                auto [y2, x2] = v[i + 1].F;
                if (x < y2 && y2 < y) {
                    r++;
                    last = 0;
                }
            }
            last = min(last, k);
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
