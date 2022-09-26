#include <string.h>
#include <stdio.h>
#include <math.h>
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pi> v(n);
    int j = 0;
    for (auto &x: v)cin >> x.F, x.S = j++;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    vi r(n);
    for (int i = 0, t = 1; i < n; i += m, t ^= 1) {
        if (t) for (int l = i; l < i + m && l < n; l++)r[v[l].S] = l - i + 1;
        else for (int l = min(n - 1, i + m - 1), xx = 1; l >= i; l--, xx ++)r[v[l].S] = xx;
    }
    cout << "YES\n";
    for (int x: r)cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
