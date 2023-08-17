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
string s;
int n;

ll d[1005][1005][2];

ll go(int x, int k, int ck) {
    if (k < 0) return 0;
    if (x == s.size()) return k == 0;
    ll &r = d[x][k][ck];
    if (r != -1) return r;
    r = 0;
    int c = s[x] - '0';
    for (int i = 0; i <= (ck ? c : 1); i++) {
        r = (r + go(x + 1, k - (i == 1), ck && i == c)) % mod;
    }
    return r;
}

void solve() {
    cin >> s;
    cin >> n;
    memset(d, -1, sizeof(d));

    ll r = 0;
    if (n == 0) r = 1;
    for (int i = 1; i < 1000; i++) {
        int x = i, c = 1;
        while (x != 1) {
            int t = 0;
            for (int k = 0; k < 20; k++)if (x >> k & 1)t++;
            x = t;
            c++;
        }

        if (c == n) {
            r = (r + go(0, i, 1)) % mod;
        }
    }
    if (n == 1)r = (r - 1 + mod) % mod;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
