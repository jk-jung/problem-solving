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

const int mod = 1000000007;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vi v(n + 1);
    vi tt(n + 1);
    tt[0] = 1;
    for (int i = 1; i <= n; i++)tt[i] = (tt[i - 1] * 2) % mod;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '1')v[i]++;
        v[i] += v[i - 1];
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        int c = v[b] - v[a - 1];
        int m = b - a + 1;
        int r = (tt[m] - tt[m - c] + mod) % mod;
        cout << r << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
