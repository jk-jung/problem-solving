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
    int n;
    cin >> n;
    vi v(n);
    vi r(n);
    int m = 0;
    for (int &x: v)cin >> x, m = max(m, x);
    int g = -1, idx = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] == m && idx == -1)idx = i;
        else if (g == -1)g = v[i];
        else g = gcd(g, v[i]);
    }
    if (g == m)cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 0; i < n; i++)cout << (i == idx ? "2 " : "1 ");
        cout << endl;
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
