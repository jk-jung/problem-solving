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

int a[505][505];
int b[505][505];
vi v[1005];
vi p[1005];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> a[i][j];
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> b[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v[i + j].pb(a[i][j]);
            p[i + j].pb(b[i][j]);
        }
    }
    for (int i = 0; i < n + m; i++) {
        sort(v[i].begin(), v[i].end());
        sort(p[i].begin(), p[i].end());
        if (v[i] != p[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
