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
    int n, s;
    cin >> n >> s;
    vi v(n);
    for (int &x: v)cin >> x;
    int r = 1 << 30;
    if (s <= v[0])r = v.back() - s;
    else if (s >= v.back()) r = s - v[0];
    else {
        int a = s - v[0];
        int b = v.back() - s;
        r = min(a, b) * 2 + max(a, b);
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
