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
    vi v(n), a, b;
    for (int &x: v)cin >> x;
    ll x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        a.pb(i % 2 == 0 ? 1 : v[i]);
        b.pb(i % 2 == 0 ? v[i] : 1);
        x += ab(v[i] - a.back());
        y += ab(v[i] - b.back());
    }
    if (x > y)a = b;
    for (int x: a)cout << x << " ";
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
