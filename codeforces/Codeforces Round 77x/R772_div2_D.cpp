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


ll mod = 1000000007;
ll d[200005];

void solve() {
    int n, p;
    cin >> n >> p;
    vector<ll> v(n), can(n);
    for (ll &x: v)cin >> x;
    sort(v.begin(), v.end());

    map<ll, int> ck;
    set<ll> q;
    for (int i = 0; i < n; i++) {
        ck[v[i]] = i;
        q.insert(v[i]);
    }

    for (int i = 0; i < n; i++) {
        ll x = v[i];
        while(x) {
            if(x & 1) x /= 2;
            else if(x % 4 == 0) x /= 4;
            else break;
            if(ck.count(x)) {
                can[i] = 1;
                break;
            }
        }
    }



    if (ck.count(1)) d[0] = 1;
    if (ck.count(2)) d[1]++;
    if (ck.count(1) || ck.count(3)) d[1]++;

    int pos = 0;
    while (pos < v.size() && v[pos] < 4)pos++;
    for (int k = 2; k < p; k++) {
        // 2^(k) ~ 2^(k + 1)
        int cnt = 0;
        while (pos < v.size() && v[pos] < (1ll << (k + 1))) {
            if (!can[pos++])cnt++;
        }
        d[k] = (d[k - 2] + d[k - 1] + cnt) % mod;
    }
    ll r = 0;
    for (int i = 0; i < p; i++)r = (r + d[i]) % mod;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
