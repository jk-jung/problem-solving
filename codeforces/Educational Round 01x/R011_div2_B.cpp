#include <cstring>
#include <cstdio>
#include <cmath>
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<vi> > a(n, vector<vi>(2));

    int c = 0, t = 1;
    for (; t <= m; t++) {
        if (a[c][0].size() == 0) a[c][0].pb(t);
        else if (a[c][1].size() == 0)a[c][1].pb(t);
        else if (c == n - 1)break;
        else a[++c][0].pb(t);
    }
    c = 0;
    for (; t <= m; t++) {
        if (a[c][0].size() == 1)a[c][0].pb(t);
        else if (a[c][1].size() == 1)a[c][1].pb(t);
        else a[++c][0].pb(t);
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 2; k++) {
            while (!a[i][k].empty()) {
                cout << a[i][k].back() << " ";
                a[i][k].pop_back();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
