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
    int n, k;
    cin >> n >> k;
    vi v(n);
    for (int &x: v)cin >> x;

    int s = v[0] + (k - 1), e = v[0] - (k - 1);
    for (int x: v) {
        s -= (k - 1);
        e += (k - 1);
        int y = x + k - 1;
        int xx = max(x, s), yy = min(e, y);
        if (yy - xx < 0) {
            cout << "NO\n";
            return;
        }
        s = max(s, x);
        e = min(e, y);
    }
    if (s <= v.back() && v.back() <= e) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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
