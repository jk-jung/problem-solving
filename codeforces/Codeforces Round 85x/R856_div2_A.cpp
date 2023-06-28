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
    n = n * 2 - 2;
    vector<string> v(n);
    int m = 0;
    for (auto &s: v) {
        cin >> s;
        m = max(m, (int) s.size());
    }
    vector<string> t;
    for (auto &s: v)if (s.size() == m)t.pb(s);

    if (t[0].substr(1) != t[1].substr(0, m - 1)) {
        swap(t[0], t[1]);
    }
    string r = t[0] + t[1].back();
    string rr = r;
    reverse(rr.begin(), rr.end());
    cout << (r == rr ? "YES" : "NO") << endl;

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
