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


int n, m;
vector<pi> v;

int d[105][105];
string r(105, 0);

int f(pi a, int x) {
    if (a.F < x && x < a.S)return -1;
    if (a.F == x || a.S == x)return 0;
    return 1;
}

bool can(pi y, pi x) {
    if (f(y, x.F) + f(y, x.S) == 0)return false;
    return true;
}

void dfs(int x, char c) {
    r[x] = c;
    for (int i = 0; i < m; i++)
        if (x != i && d[x][i]) {
            if (r[i] == c) {
                cout << "Impossible";
                exit(0);
            }
            if (!r[i])dfs(i, c == 'i' ? 'o' : 'i');
        }
}

void solve() {
    cin >> n >> m;
    v.resize(m);
    for (auto &[x, y]: v) {
        cin >> x >> y;
        if (x > y)swap(x, y);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++)if (i != j) d[i][j] = !can(v[i], v[j]);
    }

    r.resize(m);
    for (int i = 0; i < m; i++) {
        if (r[i] == 0)dfs(i, 'i');
    }

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
