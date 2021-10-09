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
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))


//// for debug
int debug = 0, qq = 0;
int v[225555];

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll lcm2(ll a, ll b) { return a / gcd(a, b) * b; }

////
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int n;
map<ll, int> ck;
ll lc[200005];
int r[200005];
vi p;
bool np[200005];

ll query(int x, int y) {
    qq++;
    if (debug) return lcm2(v[x], v[y]);
    cout << "? " << x << " " << y << endl;
    ll r;
    cin >> r;
    return r;
}

int check(map<ll, int> &m1, map<ll, int> &m2, ll x, int dif) {
    m2[x] += dif;
    int c1 = m1.count(x) ? m1[x] : 0;
    int c2 = m2[x];
    if (c1 == c2) return 1;
    if (c1 == c2 - dif) return -1;
    return 0;
}

int find_first() {
    vi can, xx;
    bool check1 = false;
    for (int i = 2; i <= n; i++) {
        lc[i] = query(1, i);
        if (ck.count(lc[i])) {
            if (lc[i] == 2) check1 = true;
            else can.pb(ck[lc[i]]);
            can.pb(ck[lc[i]] + 1);
        }
    }
    sort(can.begin(), can.end());
    can.resize(unique(can.begin(), can.end()) - can.begin());
//    if (debug)for (auto x: can) cout << " can " << x << endl;

    for (auto x: can) {
        bool ok = true;
        for (int i = 2; i <= n; i++)
            if (lc[i] % x || lc[i] / x > x + n - 1) {
                ok = false;
                break;
            }
        if (ok)xx.pb(x);
    }

    if (check1) {
        vector<ll> vv2, vv3;
        for (int i = 2; i <= n; i++) {
            vv2.pb(i);
            vv3.pb(lc[i]);
        }
        sort(vv3.begin(), vv3.end());
        if (vv2 == vv3) {
            if (xx.size() > 0)xx[0] = 1;
            else xx.pb(1);
        }
    }
    if (debug)for (auto x: xx) cout << " xx " << x << endl;
    assert(xx.size() == 1);
    return xx[0];
}

int get_first_range() {
    map<ll, int> target, cur;
    target[r[1]]++;
    for (int i = 2; i <= n; i++)target[lc[i]]++;
    int s = r[1] - n + 1, e = r[1] + n - 1;

    int matched = 0;
    vi segs;
    for (int i = s; i <= e; i++) {
        matched += check(target, cur, lcm2(r[1], i), 1);
        if (i - n >= s)
            matched += check(target, cur, lcm2(r[1], i - n), -1);
        if (matched == target.size()) segs.pb(i - n + 1);
    }

    map<ll, vi> idx;
    for (int i = 2; i <= n; i++) idx[lc[i]].pb(i);

    if (debug)for (auto x: segs) cout << " SEG " << x << endl;
    if (segs.size() > 1) {
        assert(segs.size() == 2);
        int t1 = segs[0];
        int t2 = segs[1] + n - 1;

        vector<pair<int, int>> tt = {{t1, t1}, {segs[1], t2}};
        for (auto[s0, ss]: tt) {
            for (int ss_idx: idx[lcm2(r[1], ss)]) {
                vector<ll> v1, v2;
                for (int i = 1; i <= n; i++) {
                    if (i == ss_idx)continue;
                    v1.pb(query(ss_idx, i));
                }
                for (int i = s0; i < s0 + n; i++)if (i != ss)v2.pb(lcm2(ss, i));
                sort(v1.begin(),v1.end());
                sort(v2.begin(),v2.end());
                if(v1 == v2)segs[0] = s0;
            }
        }
    }

    return segs[0];
}

int get_rand(int x = -1, int y = -1) {
    int t = x;
    while (t == x || t == y) t = rnd() % n + 1;
    return t;
}

int max_prime(ll t) {
    int r = 0;
    for (int x: p) {
        if ((ll) x * x > t)break;
        while (t % x == 0)t /= x, r = max(r, x);
    }
    return max((int) t, r);
}

void solve2() {
    int p_i1, p_i2, p_val = -1;
    for (int i = 0; i < 5000; i++) {
        int i1 = get_rand();
        int i2 = get_rand(i1);
        int p1 = max_prime(query(i1, i2));

        if (p1 > p_val) {
            p_val = p1;
            p_i1 = i1;
            p_i2 = i2;
        }
    }
    int i3 = get_rand(p_i1, p_i2);
    ll val = query(p_i1, i3);
    int p_i0 = val % p_val == 0 ? p_i1 : p_i2;

    for (int i = 1; i <= n; i++)r[i] = 0;
    r[p_i0] = p_val;
    for (int i = 1; i <= n; i++) {
        if (r[i])continue;
        r[i] = query(p_i0, i) / p_val;
    }

    cout << "! ";
    for (int i = 1; i <= n; i++)cout << r[i] << " ";
    cout << endl;
}

void solve() {
    cin >> n;
    if (debug) {
//        for (int i = 1; i <= n; i++)cin >> v[i];

        n = rnd() % 10 + 5;
        int s = rnd() % 150 + 1;
        vector<pi> vvvv;
        for(int i=0;i<n;i++)vvvv.pb({rand(), s+i});
        sort(vvvv.begin(), vvvv.end());
        for(int i=0;i<n;i++)v[i+1] = vvvv[i].S;
        cout << "? ";
        for (int i = 1; i <= n; i++)cout << v[i] << " ";
        cout << endl;
    }

    if (n > 100) return solve2();

    r[1] = find_first();
    int ss = get_first_range();

    map<ll, vi> val, idx;
    vector<pi> rr;
    for (int i = ss; i < ss + n; i++) if (i != r[1]) val[lcm2(r[1], i)].pb(i);
    for (int i = 2; i <= n; i++) idx[lc[i]].pb(i);

    for (auto[l, vv]: val) if (vv.size() == 1) rr.pb({idx[l][0], vv[0]});


    for (auto[l, vv]: val) {
        vi &id = idx[l];
        if (vv.size() == 1) continue;

        for (auto[i1, v1]: rr) {
            map<ll, int> ccc;
            for (int y: vv) ccc[lcm2(y, v1)] = 1;
            if (ccc.size() != vv.size())continue;
            for (int i = 0; i < vv.size(); i++) {
                ll l1 = query(i1, id[i]);
                for (int &j: vv) {
                    if (lcm2(j, v1) == l1)rr.pb({id[i], j});
                }
            }
            break;
        }
        r[id[0]] = vv[0];
    }

    assert(rr.size() == n - 1);
    for (auto[i, tmp]: rr) r[i] = tmp;
    cout << "! ";
    for (int i = 1; i <= n; i++)cout << r[i] << " ";
    cout << endl;
    if (debug) for (int i = 1; i <= n; i++)assert(r[i] == v[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 200000; i++)ck[lcm2(i, i + 1)] = i;
    for (int i = 2; i <= 200000; i++) {
        if (np[i])continue;
        p.pb(i);
        for (int j = i + i; j <= 200000; j += i)np[j] = true;
    }

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}