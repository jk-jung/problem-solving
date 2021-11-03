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

int n, m = 1 << 13;
vi v[5005];
int d[2][1 << 13];
int d2[1 << 13];

void solve() {
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        v[x].pb(i + 2);
    }

    d[0][0] = 1;
    int x = 0, y = 1;
    for (int i = 1; i <= 5000; i++) {
        if (v[i].empty())continue;
        for (int k = 0; k < m; k++) {
            int p = d[x][k];
            if (!p) continue;

            int p2 = lower_bound(v[i].begin(), v[i].end(), p + 1) - v[i].begin();
            if (p2 == v[i].size())continue;
            d[y][k ^ i] = v[i][p2];
        }
        for (int k = 0; k < m; k++) {
            if (d[y][k] && (!d[x][k] || d[x][k] > d[y][k]))
                d[x][k] = d[y][k];
            d[y][k] = 0;
        }
    }
    vi r;
    for(int k=0;k<m;k++)if(d[0][k])r.pb(k);
    cout << r.size() << endl;
    for(int x: r)cout << x <<" ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        solve();
}
