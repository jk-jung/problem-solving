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

int n, m;
vi v[100005];
vi r[4];
int ck[100005];

void dfs(int x, int p = 2) {
    ck[x] = p;
    r[p].pb(x);
    for (int y: v[x]) {
        if (!ck[y])dfs(y, p ^ 1);
        else if (ck[y] == p) {
            cout << -1 << endl;
            exit(0);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for (int i = 1; i <= n; i++) {
        if (!ck[i])dfs(i);
    }
    cout << r[2].size() << endl;
    for (int x: r[2])cout << x << ' ';
    cout << endl;
    cout << r[3].size() << endl;
    for (int x: r[3])cout << x << ' ';
    cout << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
