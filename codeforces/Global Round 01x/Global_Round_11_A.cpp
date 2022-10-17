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
    int n, s1 = 0, s2 = 0;
    vi a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < 0)a.pb(x), s1 -= x;
        else if (x > 0)b.pb(x), s2 += x;
        else c.pb(0);
    }
    if (s1 == s2) {
        cout << "NO\n";
        return;
    }

    if (s1 < s2) swap(a, b);
    cout << "YES\n";
    for (int x: a)cout << x << " ";
    for (int x: b)cout << x << " ";
    for (int x: c)cout << x << " ";
    cout << '\n';
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
