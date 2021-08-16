#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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

#define mod 998244353

int d[55][100005];
int ss[55][100005];
int ck[55][100005], CK;
int LL[55], L[55], R[55], RR[55];
int n, m;
ll rst[100005];

int go(int x, int rest) {
    if (x == n) return 1;

    int &r = d[x][rest];
    if (ck[x][rest] == CK) return r;
    r = 0;
    ck[x][rest] = CK;

    int M = min(R[x], rest);
    for (int i = L[x]; i <= M; i++) {
        r = int(((ll) r + go(x + 1, rest - i)) % mod);
    }

    return r;
}

int test(int mm) {
    for (int i = 0; i <= mm; i++) {
        d[0][i] = ss[0][i] = 0;
        if (L[0] <= i && i <= R[0])
            d[0][i] = 1;
        if (i > 0)
            ss[0][i] += ss[0][i - 1] + d[0][i];
    }
    for (int i = 1; i < n; i++) {
        for (int k = 1; k <= mm; k++) {
            int s = max(0, k - R[i]);
            int e = max(0, k - L[i]);

            if(s == 0) d[i][k] = ss[i-1][e];
            else d[i][k] = ((ll)ss[i-1][e] - ss[i-1][s-1] + mod) % mod;
        }

        for (int k = 0; k <= mm; k++) {
            ss[i][k] = 0;
            if(i)
                ss[i][k] = (ss[i][k - 1] + d[i][k]) % mod;
        }
    }

    return ss[n-1][mm];
}

void solve() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> LL[i] >> RR[i];

    for (int i = m; i >= 1; i--) {
        for (int k = 0; k < n; k++) {
            L[k] = (LL[k] + i - 1) / i;
            R[k] = RR[k] / i;
        }
        CK++;
        rst[i] = (rst[i] + test(m / i)) % mod;

        for (int k = i + i; k <= m; k += i)
            rst[i] = (rst[i] - rst[k] + mod) % mod;
    }

    cout << rst[1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    solve();
}
