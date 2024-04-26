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
    int n, m, k;
    cin >> n >> m >> k;
    k = m - k;
    vi v(n), o, e;
    for (int &x: v) {
        cin >> x;
        if (x % 2)o.pb(x);
        else e.pb(x);
    }
    int dif = int(o.size()) - k;
    if (o.size() < k || dif % 2 == 1 || dif / 2 + e.size() < m - k) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < k; i++) {
        if (i == k - 1 && m - k == 0)break;
        cout << 1 << " " << o.back() << endl;
        o.pop_back();
    }
    for (int i = 0; i < m - k - 1; i++) {
        if (!o.empty()) {
            cout << 2 << " " << o.back() << " ";
            o.pop_back();
            cout << o.back() << endl;
            o.pop_back();
        } else {
            cout << 1 << " " << e.back() << endl;
            e.pop_back();
        }
    }
    cout << e.size() + o.size() << " ";
    for (int x: e) cout << x << " ";
    for (int x: o) cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
