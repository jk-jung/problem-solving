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

bool f(int n, int m, vector<string> v) {
    if (n % 3 == 0) {
        int t = n / 3;
        set<char> s;
        s.insert(v[0][0]);
        s.insert(v[t][0]);
        s.insert(v[t + t][0]);
        if (s.size() == 3) {
            bool ok = true;
            for (int i = 0; i < t; i++) {
                for (int j = 0; j < m; j++) {
                    if (v[0][0] != v[i][j]) ok = false;
                    if (v[t][0] != v[t + i][j]) ok = false;
                    if (v[t + t][0] != v[t + t + i][j]) ok = false;
                }
            }
            if (ok) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n), vv(m);
    for (auto &x: v)cin >> x;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)vv[j] += v[i][j];
    }

    cout << (f(n, m, v) || f(m, n, vv) ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
