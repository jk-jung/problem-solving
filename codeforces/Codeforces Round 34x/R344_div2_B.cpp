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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> v(n, vi(m));

    vector<tuple<int, int, int> > q;
    set<int> a, b;
    for (int i = 0; i < n; i++)a.insert(i);
    for (int i = 0; i < m; i++)b.insert(i);
    for (int i = 0, x, y, z; i < k; i++) {
        cin >> x >> y >> z;
        q.emplace_back(x, --y, z);
    }

    for (int t = k - 1; t >= 0; t--) {
        auto [x, y, z] = q[t];
        if (x == 1) {
            if (a.count(y)) {
                a.erase(y);
                for(auto p:b)v[y][p] = z;
            }
        } else {
            if (b.count(y)) {
                b.erase(y);
                for(auto p:a)v[p][y] = z;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
