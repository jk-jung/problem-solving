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

const int LIMIT = 548;

int d[LIMIT + 10][LIMIT + 10];
int cc[300005];
int flag[300005], CK = 0;
vi val;
vi tot;

void solve() {
    int n, q;
    cin >> n >> q;
    vi v(n);
    map<int, vi> ck;
    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
        ck[v[i]].pb(i);
    }

    int idx = 0;
    for (auto&[k, vv]: ck) {
        if (vv.size() >= LIMIT) {
            val.pb(k);
            for (int i: vv)d[idx][i / LIMIT]++;
            for (int i = 1; i <= n / LIMIT; i++) d[idx][i] += d[idx][i - 1];
            idx++;
        }
    }

    while (q--) {
        int s, e;
        cin >> s >> e;
        s--, e--;
        CK++;
        int cnt = 0, m = e - s + 1;

        if (m >= LIMIT * 2) {
            int ss = 1 << 30;
            int ee = -ss;

            for (int k: val) cc[k] = 0;
            for (int i = s; i <= e;) {
                if (i % LIMIT == 0 && i + LIMIT - 1 <= e) {
                    ss = min(ss, i / LIMIT);
                    ee = max(ee, i / LIMIT);
                    i += LIMIT;
                } else {
                    cc[v[i]]++;
                    i++;
                }
            }
            for (int i = 0; i < idx; i++) {
                int k = val[i];
                if (ss <= ee) {
                    cc[k] += d[i][ee];
                    if (ss)cc[k] -= d[i][ss - 1];
                }
                cnt = max(cnt, cc[k]);
            }
        } else {
            for (int i = s; i <= e; i++) {
                int x = v[i];
                if (flag[x] != CK) cc[x] = 0;
                flag[x] = CK;
                cnt = max(cnt, ++cc[x]);
            }
        }

        if (cnt <= (m + 1) / 2) cout << 1 << '\n';
        else {
            int rest = cnt - (m - cnt + 1);
            cout << rest + 1 << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
