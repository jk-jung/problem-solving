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

vector<pi> c[5000005];
vi vv[2500002];

pair<pi, pi> check(vector<pi> &v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto &x = v[i];
            auto &y = v[j];

            if (x.F != y.F && x.F != y.S && x.S != y.F && x.S != y.S) {
                return mp(x, y);
            }
        }
    }
    return mp(mp(-1, 0), mp(0, 0));
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    int idx = 0;
    for (int &x: v)cin >> x, vv[x].pb(++idx);
    for (int i = 1; i <= 2500000; i++)
        if (vv[i].size() >= 4) {
            cout << "YES\n";
            for(int j=0;j<4;j++)cout << vv[i][j] <<" ";
            cout << endl;
            return;
        }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = v[i] + v[j];
            c[x].pb({i + 1, j + 1});

            if(c[x].size() >= 2) {
                auto r = check(c[x]);
                if(r.F.F != -1) {
                    cout << "YES\n";
                    cout << r.F.F <<" " <<r.F.S <<" " << r.S.F <<" " << r.S.S << endl;
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
