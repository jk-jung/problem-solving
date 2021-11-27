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

int n;
ll d[20000005];
ll cnt[20000005];
int prime[20000005];

const int MAX = 20000000;

void fast_factorization_for_many_numbers() {
    for (int i = 2; i <= MAX; i++) {
        if (prime[i])continue;
        for (int j = i + i; j <= MAX; j += i) prime[j] = i;
    }
}

void dfs(int cur, map<int, int>::iterator it, map<int, int> &ck, vi &t) {
    if (it == ck.end()) {
        t.pb(cur);
        return;
    }

    int x = it->F;
    int y = it->S;
    it++;
    for (int i = 0; i <= y; i++) {
        dfs(cur, it, ck, t);
        cur *= x;
    }
}

void solve() {
    cin >> n;

    for (int i = 0, x; i < n; i++) {
        cin >> x;

        map<int,int> fac;
        vi ds;

        while (prime[x]) fac[prime[x]]++, x /= prime[x];
        if (x > 1) fac[x]++;

        dfs(1, fac.begin(), fac, ds);
        for (int y: ds)cnt[y] ++;
    }

    ll r = n;
    d[1] = n;
    for (int i = 2; i <= MAX; i++) {
        if (!cnt[i])continue;

        int x = i;
        map<int,int> fac;
        vi ds;

        while (prime[x]) fac[prime[x]]++, x /= prime[x];
        if (x > 1) fac[x]++;

        dfs(1, fac.begin(), fac, ds);

        for (int y: ds) {
            d[i] = max(d[i], d[y] + (i * cnt[i] - y * cnt[i]));
        }
        r = max(r, d[i]);
    }
    cout << r << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fast_factorization_for_many_numbers();
    solve();
}
