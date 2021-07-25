#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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


ll mod = 998244353;

int n;
ll x[200005];
ll y[200005];
ll ss[200005];
ll sum[200005];
int s[200005];
int pos[200005];
pi yy[200005];


void solve() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> s[i];
        yy[i] = {y[i], i};
    }
    sort(yy, yy + n);
    for (int i = 0, p = 0; i < n; i++) {
        while (x[p] < yy[i].F) p++;
        pos[yy[i].S] = p;
    }

    for (int i = 0; i < n; i++) {
        int k = pos[i];
        ss[i] = x[k] - y[i];
        ss[i] %= mod;

        if (i != k) {
            ss[i] = (ss[i] + x[i] - x[k]) % mod;
            ss[i] = (ss[i] + sum[i - 1]) % mod;
            if (k > 0) ss[i] = (ss[i] - sum[k - 1] + mod) % mod;
        }
        sum[i] = ss[i];
        if(i >0) sum[i] = (sum[i] + sum[i-1]) % mod;
    }

    ll r = (x[0] + 1) % mod;
    for (int i = 0; i < n; i++) {
        if (i > 0) r = (r + x[i] - x[i - 1]) % mod;
        if (s[i]) r = (r + ss[i]) % mod;
    }
    cout <<r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
