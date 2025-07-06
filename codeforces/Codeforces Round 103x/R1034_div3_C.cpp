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
    vi v(n), a(n), b(n);
    for (int &x: v)cin >> x;
    a[0] = v[0];
    for (int i = 1; i < n; i++)a[i] = min(a[i - 1], v[i]);
    b.back() = v.back();
    for (int i = n - 2; i >= 0; i--)b[i] = max(b[i + 1], v[i]);
    for (int i = 0; i < n; i++)
        cout << (v[i] == a[i] || v[i] == b[i] ? 1 : 0);
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
