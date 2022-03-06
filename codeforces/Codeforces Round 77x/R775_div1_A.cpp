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


ll calc(vector<vi> &v) {
    int n = v.size();
    int m = v[0].size();
    map<int, int> tot;
    map<int, map<int, int>> ck;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ck[v[i][j]][j]++;
            tot[v[i][j]]++;
        }
    }
    ll r = 0;
    for (auto &[k, cc]: ck) {
        int last_pos = 0, last_cnt = 0;
        int tt = tot[k];
        for (auto[pos, cnt]: cc) {
            ll dif = pos - last_pos;
            ll left = tt - last_cnt;

            r += dif * left * last_cnt;
            last_pos = pos;
            last_cnt += cnt;
        }
    }
    return r;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> v(n, vi(m)), v2(m, vi(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            v2[j][i] = v[i][j];
        }

    ll r = calc(v) + calc(v2);
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
