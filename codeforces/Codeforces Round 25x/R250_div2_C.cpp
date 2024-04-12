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

vi e[100005];
int a[100005];
int used[100005];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pi> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].F;
        v[i].S = i;
        a[i] = v[i].F;
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        e[x].pb(y);
        e[y].pb(x);
    }
    int r = 0;
    for (int i = 0; i < n; i++) {
        int x = v[i].S;
        used[x] = 1;
        for (auto y: e[x]) if (!used[y]) r += a[y];
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
