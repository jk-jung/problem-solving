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

/*
 7
       2 5
     6 5
     2 3
    1 2
    2 4
    6 7
 */
void solve() {
    int n;
    cin >> n;
    vector<vector<pi>> v(n);
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        x--, y--;
        v[x].pb({y, i}), v[y].pb({x, i});
    }
    vi d(n);
    queue<pi> q;
    q.emplace(0, -1);
    d[0] = 1;
    while (!q.empty()) {
        auto [x, t] = q.front();
        q.pop();
        for (auto [y, z]: v[x]) {
            if (!d[y]) {
                d[y] = d[x] + (z < t);
                q.emplace(y, z);
            }
        }
    }
    cout << *max_element(d.begin(), d.end()) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
