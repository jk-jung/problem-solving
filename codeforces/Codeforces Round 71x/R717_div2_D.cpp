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


int MAX = 100000;
int p[100005][20];
set<int> fac[100005];
int cnt[100005];

void solve() {
    int n, q;
    cin >> n >> q;
    vi v(n);
    for (int &x: v)cin >> x;

    for (int i = 0, e = 0; i < n; i++) {
        while (e < n) {
            bool ok = true;
            for (int x: fac[v[e]]) {
                if (cnt[x]) {
                    ok = false;
                    break;
                }
            }
            if (!ok)break;
            for (int x: fac[v[e]]) cnt[x]++;
            e++;
        }
        p[i][0] = e;
        for (int x: fac[v[i]]) cnt[x]--;
    }

    for (int k = 1; k < 20; k++) {
        for (int i = 0; i < n; i++) {
            p[i][k] = p[p[i][k - 1]][k - 1];
            if(!p[i][k])p[i][k] = n;
        }
    }

    while (q--) {
        int s, e;
        cin >> s >> e;
        s--, e--;
        int r = 1;
        for (int k = 19; k >= 0; k--) {
            if (p[s][k] <= e) {
                r += 1 << k;
                s = p[s][k];
            }
        }
        cout << r << '\n';
    }

}

void fast_factorization_for_many_numbers() {
    vector<int> prime(MAX + 1);
    for (int i = 2; i <= MAX; i++) {
        if (prime[i])continue;
        for (int j = i + i; j <= MAX; j += i) prime[j] = i;
    }

    for (int i = 2; i <= MAX; i++) {
        int x = i;
        vi factors;

        while (prime[x]) fac[i].insert(prime[x]), x /= prime[x];
        if (x > 1) fac[i].insert(x);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fast_factorization_for_many_numbers();
    solve();
}
