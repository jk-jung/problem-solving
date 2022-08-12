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
    int n;
    cin >> n;
    vector<pi> v(n - 1);
    vi cnt(n + 1);
    vi r(n - 1, -1);
    for (auto &[x, y]: v)cin >> x >> y, cnt[x]++, cnt[y]++;
    for (int i = 1; i <= n; i++)
        if (cnt[i] >= 3) {
            int t = 0;
            for (int j = 0; j < v.size(); j++) {
                if (v[j].F == i || v[j].S == i) {
                    r[j] = t++;
                }
            }
            for (int &x: r)
                if (x == -1)x = t++;
            break;
        }
    if (r[0] == -1)
        for (int i = 0; i < r.size(); i++)r[i] = i;
    for (int x: r)cout << x << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
