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

int mod = 1000000007;
vi pal;
int d[500][40005];

int go(int x, int idx) {
    if (x == 0)return 1;
    if (idx == pal.size())return 0;

    int &r = d[x][idx];
    if (r != -1) return r;
    r = 0;

    int k = pal[idx];
    for (int i = 0; i * k <= x; i++) {
        r = (r + go(x - i * k, idx + 1)) % mod;
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    cout << d[pal.size()][n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 40000; i++) {
        string a = to_string(i);
        string b = a;
        reverse(a.begin(), a.end());
        if (a == b)pal.pb(i);
    }

    d[0][0] = 1;
    for (int k = 1; k <= pal.size(); k++) {
        int v = pal[k - 1];
        vi ss(v);
        for (int i = 0; i <= 40000; i++) {
            d[k][i] = d[k - 1][i];
            if (i - v >= 0)d[k][i] = (d[k][i] + d[k][i - v]) % mod;
        }
    }

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
