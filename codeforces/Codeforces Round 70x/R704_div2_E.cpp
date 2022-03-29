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

int n, m;
vector<vi> v, dif, pos;
vi cc;


bool check1() {
    int tot = 0;
    vi cnt(m), vv(m);
    for (int i = 1; i < n; i++) {
        if (cc[i] != 3)continue;
        for (int x: pos[i])cnt[x]++, vv[x] = v[i][x];
        tot++;
        break;
    }
    for (int j = 0; j < m; j++) {
        if (cnt[j] != tot)continue;
        int val = vv[j];

        for (int i = 1; i < n; i++) {
            int c = cc[i];
            if (dif[i][j]) {
                if (v[i][j] == val)c--;
            } else c++;
            if (c > 2)goto NO;
        }

        cout << "YES\n";
        v[0][j] = val;
        for (int x: v[0])cout << x << " ";
        cout << endl;
        return true;

        NO:;
    }
    return false;
}


bool check2(int tar) {
    int tot = 0;
    vi cnt(m), vv(m), vv2(m);
    for (int i = 1; i < n; i++) {
        if (cc[i] != tar)continue;
        for (int x: pos[i])cnt[x]++, vv[x] = v[i][x];
        tot++;
        break;
    }
    vi jj;
    for (int j = 0; j < m; j++)if (cnt[j] == tot) jj.pb(j);
    for (int i0 = 0; i0 < jj.size(); i0++) {
        for (int i1 = 0; i1 < jj.size(); i1++) {
            if (i0 == i1)continue;
            int j1 = jj[i0];
            int j2 = jj[i1];

            int val1 = vv[j1];
            int val2 = vv[j2];

            if (tar == 3) {
                for (int i = 1; i < n; i++) {
                    int c = cc[i];
                    if (dif[i][j1]) {
                        if (v[i][j1] == val1)c--;
                    } else c++;
                    if (c == 4)goto NO2;
                    if (c == 3) {
                        if(dif[i][j2]) {
                            val2 = v[i][j2];
                            break;
                        }
                        else goto NO2;
                    }
                }
            }

            for (int i = 1; i < n; i++) {
                int c = cc[i];

                if (dif[i][j1]) {
                    if (v[i][j1] == val1)c--;
                } else c++;

                if (dif[i][j2]) {
                    if (v[i][j2] == val2)c--;
                } else c++;
                if (c > 2)goto NO2;
            }

            cout << "YES\n";
            v[0][j1] = val1;
            v[0][j2] = val2;
            for (int x: v[0])cout << x << " ";
            cout << endl;
            return true;

            NO2:;
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    v.resize(n, vi(m));
    dif.resize(n, vi(m));
    for (auto &x: v)for (int &y: x)cin >> y;

    cc.resize(n);
    pos.resize(n);
    int m_cnt = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (v[i][j] != v[0][j]) {
                dif[i][j] = 1;
                cc[i]++;
                pos[i].pb(j);
                m_cnt = max(m_cnt, cc[i]);
            }
        }
    }

    if (m_cnt > 4) {
        cout << "NO\n";
        return;
    }
    if (m_cnt <= 2) {
        cout << "YES\n";
        for (int x: v[0])cout << x << " ";
        cout << endl;
        return;
    }

    if (m_cnt == 3 && check1())return;
    if (m_cnt == 3 && check2(3))return;
    if (m_cnt == 4 && check2(4))return;

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
