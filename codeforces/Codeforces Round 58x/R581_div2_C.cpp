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
int a[105][105];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
            if (s[j] == '1')a[i][j] = 1;
            else a[i][j] = 10000000;
    }
    cin >> m;
    vi v(m);
    for (int i = 0; i < m; i++)cin >> v[i];
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j)
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    vi r;
    for (int z: v) {
        z--;
        if (r.size() <= 1)r.pb(z);
        else {
            int x = r[r.size() - 2];
            int y = r[r.size() - 1];
            if (a[x][z] == a[x][y] + a[y][z])r.pop_back();
            r.pb(z);
        }
    }

    cout << r.size() << endl;
    for (int x: r)cout << x + 1 << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
