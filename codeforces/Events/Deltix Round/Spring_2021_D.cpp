#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

int n, m, p;
ll v[200005];
ll r;

void calc(int x) {
    vi bit;
    for (int i = 0; i < m; i++) if (v[x] >> i & 1) bit.pb(i);
    int N = bit.size();
    vi d(1 << N);

    for (int i = 0; i < n; i++) {
        int st = 0;
        for (int k = 0; k < N; k++)
            if (v[i] >> bit[k] & 1) st |= 1 << k;
        d[st]++;
    }

    for (int k = 0; k < N; k++) {
        for (int st = 0; st < (1 << N); st++) {
            if (!(st & (1 << k)))
                d[st] += d[st ^ (1 << k)];
        }
    }

    for (int st = (1 << N) - 1; st > 0; st--) {
        if (d[st] >= (n + 1) / 2 && __builtin_popcountll(st) > __builtin_popcountll(r)) {
            ll nt = 0;
            for (int k = 0; k < N; k++)if (st >> k & 1) nt |= 1ll << bit[k];
            r = nt;
        }
    }
}

void solve() {
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v[i] = (ll) bitset<64>(s).to_ullong();
    }

    ll used = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            if ((v[i] >> k & 1) && !(used >> k & 1)) {
                calc(i);
                break;
            }
        }
        used |= v[i];
    }
    for (int i = m - 1; i >= 0; i--) cout << (r >> i & 1);
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}

