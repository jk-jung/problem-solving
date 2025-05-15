#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

int a[10005], b[10005], c[10005];
int used[10005];

void solve() {
    int n;
    cin >> n;
    vector<pi> v(n);
    for (int i = 0; i < n; i++)cin >> v[i].F, v[i].S = i;
    sort(v.rbegin(), v.rend());

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)cin >> a[i] >> b[i] >> c[i], a[i]--, b[i]--;

    int r = 0;
    vi parents(n, -1);
    used[v[0].S] = 1;
    for (int t = 1; t < n; t++) {
        int p = v[t].S;
        int cost = 1 << 30;
        for (int i = 0; i < m; i++) {
            if (used[a[i]] && b[i] == p && c[i] < cost) {
                cost = c[i];
                parents[p] = a[i];
            }
        }
        used[p] = 1;
        if (parents[p] == -1) {
            cout << -1 << endl;
            return;
        }
        r += cost;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
