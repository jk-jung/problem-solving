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
    ll r = 0;
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    for (int i = 0; i < n - k; i++)r += v[i];
    ll t = r;
    for (int i = 0, e = n - k; i < k * 2; i += 2, e++) {
        t += v[e];
        t -= v[i] + v[i + 1];
        r = max(r, t);
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
