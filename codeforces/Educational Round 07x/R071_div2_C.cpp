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
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    vector<vector<ll>> d(n + 1, vector<ll>(2, 1ll << 60));
    d[0][0] = b;
    for (int i = 1; i <= n; i++) {
        char x = s[i - 1];
        char y = i < n ? s[i] : '0';
        if (x == '0' && y == '0')
            d[i][0] = min(d[i - 1][0] + a + b, d[i - 1][1] + a + a + b);
        d[i][1] = min(d[i - 1][0] + a + a + b + b, d[i - 1][1] + a + b + b);
    }
    cout << d[n][0] << endl;
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
