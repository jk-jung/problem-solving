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

int n;
vi v[200005];
ll r[200005];
int cnt[200005];
int S[200005];
int E[200005];
int CK;

void go(int x, int y) {
    S[x] = CK++;
    cnt[x] = 1;
    for (int z : v[x]) {
        if (z == y) continue;
        go(z, x);
        cnt[x] += cnt[z];
    }
    E[x] = CK;
}


bool is_parent(int x, int y) {
    return S[x] <= S[y] && E[y] <= E[x];
}


void process() {
    int x = 0, y = 0, xx, yy;
    ll t = -1;
    for (int i = 0; i < n; i++) {
        if (is_parent(i, x) || is_parent(i, y)) {
        } else if (is_parent(x, i)) {
            if (x == 0)
                for (int z : v[0]) if (is_parent(z, i)) xx = z;
            x = i;
        } else if (is_parent(y, i)) {
            if (y == 0)
                for (int z : v[0]) if (is_parent(z, i)) yy = z;
            y = i;
        } else {
            return;
        }
        if(xx == yy) return;

        if (x == y) {
            r[1] = r[0];
            for (int z : v[0]) {
                r[1] -= (ll) cnt[z] * (cnt[z] - 1) / 2;
            }
        } else if (y == 0) {
            if (t == -1) {
                t = 1;
                for (int z : v[0]) {
                    if (!is_parent(z, x)) t += cnt[z];
                }
            }
            r[i + 1] = (ll) cnt[x] * t;
        } else {
            r[i + 1] = (ll) cnt[x] * cnt[y];
        }
    }
}


void solve() {

    cin >> n;
    for (int i = 1; i < n; i++) {
        int s, e;
        cin >> s >> e;
        v[s].pb(e);
        v[e].pb(s);
    }

    r[0] = (ll) n * (n - 1) / 2;

    CK = 0;
    go(0, -1);
    process();

    ll s = 0;
    for (int i = n; i >= 0; i--) {
        r[i] -= s;
        s += r[i];
    }

    for (int i = 0; i <= n; i++) cout << r[i] << " ";
    cout << '\n';

    for (int i = 0; i <= n; i++) {
        v[i].clear();
        r[i] = 0;
        cnt[i] = 0;
        S[i] = E[i] = 0;
    }
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
