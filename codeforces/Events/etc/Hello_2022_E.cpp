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


int find_pos(vi &v, int need) {
    int s = 0, e = (int) v.size() - 1, r = (int)v.size();
    while (s <= e) {
        int m = (s + e) / 2;
        if (v[m] <= need) e = m - 1, r = m;
        else s = m + 1;
    }
    return r;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n), E(m), L(m), R(m), nd(m);
    vector<vi> b(m);
    vector<ll> b_sum(m);

    for(int &x:a)cin>>x;
    for (vi &t: b) {
        int l;
        cin >> l;
        t.resize(l);
        for (int &x: t)cin >> x;
    }

    vector<int> v;
    for (int i = 0; i < m; i++) {
        auto &t = b[i];
        ll s = 0, l = (ll) t.size();
        for (int x: t)s += x;
        b_sum[i] = s;
        int need = (s + l - 1) / l;
        nd[i] = need;
        v.pb(need);
    }
    sort(a.begin(), a.end(), greater<>());
    sort(v.begin(), v.end(), greater<>());

    for (int i = 0; i < m; i++) {
        if (i) {
            E[i] = E[i - 1];
            L[i] = L[i - 1];
            R[i] = R[i - 1];
        }
        if (a[i] >= v[i]) E[i]++;
        if (i + 1 < n && a[i + 1] >= v[i]) R[i]++;
        if (i && a[i - 1] >= v[i]) L[i]++;
    }

    string r;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < b[i].size(); j++) {
            ll s = b_sum[i] - b[i][j], l = (ll) b[i].size() - 1;
            int need = (s + l - 1) / l;
            int pos = find_pos(v, need);
            int x = find_pos(v, nd[i]);

            if(pos > x) pos --;

            int ss = min(pos, x);
            int ee = max(pos, x);

            int cnt = 0;
            if (ss > 0)cnt += E[ss - 1];
            if (ee + 1 <= m - 1)cnt += E[m - 1] - E[ee];
            if (need <= a[pos]) cnt++;
            if (pos < x) {
                cnt += R[ee - 1];
                if (ss > 0)cnt -= R[ss - 1];
            } else if (pos > x) {
                cnt += L[ee];
                cnt -= L[ss];
            }

            r += (cnt == m ? '1': '0');
            if(r == "00000000000000000000000000000000000000000000000000000000000000000000"){
                 r =r;
            }
        }
    }

    cout << r << endl;
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

/*
 1
 8 8
10 11 12 13 14 15 16 17
 9
8 9 10 11 12 13 14 15 16
9
9 10 11 12 13 14 15 16 17
9
10 11 12 13 14 15 16 17 18
9
19 11 12 13 14 15 16 17 18
9
19 20 12 13 14 15 16 17 18
9
19 20 21 13 14 15 16 17 18
9
11 10 12 11 10 12 11 10 12
9
10 10 10 10 10 11 10 10 10
 */