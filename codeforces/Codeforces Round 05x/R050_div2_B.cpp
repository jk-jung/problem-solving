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
vector<string> v;

bool sf(pi a, pi b) {
    if (a.F * a.S == b.F * b.S)return a.F < b.F;
    return a.F * a.S < b.F * b.S;
}

bool ok(int x, int y) {
    set<vector<string>> s;
    for (int i = 0; i < n; i += x) {
        for (int j = 0; j < m; j += y) {
            vector<string> t(x);
            set<vector<string>> ss;
            for (int p = 0; p < x; p++) {
                for (int q = 0; q < y; q++) {
                    t[p] += v[i + p][j + q];
                }
            }
            if (x == y) {
                vector<string> t2 = t;
                for (int k = 0; k < 4; k++) {
                    for (int p = 0; p < x; p++)
                        for (int q = 0; q < y; q++)
                            t2[p][q] = t[q][x - p - 1];
                    t = t2;
                    ss.insert(t);
                }
            } else {
                ss.insert(t);
                vector<string> t2;
                for (int p = 0; p < x; p++) {
                    t2.pb("");
                    for (int q = 0; q < y; q++) {
                        t2[p] += t[x - p - 1][y - q - 1];
                    }
                }
                ss.insert(t2);
            }

            for (auto &x: ss) {
                if (s.count(x))return false;
                s.insert(x);
            }
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    v.resize(n);
    vector<pi> r;
    for (auto &x: v)cin >> x;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (n % i || m % j)continue;
            int x = n / i, y = m / j;

            if (ok(x, y))r.pb({x, y});
        }
    cout << r.size() << endl;
    sort(r.begin(), r.end(), sf);
    cout << r[0].F << ' ' << r[0].S << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
