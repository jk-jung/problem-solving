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
    vi v(n);
    for (int &x: v)cin >> x;
    vector<pi> r;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n - i + 1; j++) {
            if (v[j] < v[j - 1]) {
                swap(v[j], v[j - 1]);
                r.pb({j - 1, j});
            }
        }
    }
    for (auto [x, y]: r)cout << x + 1 << ' ' << y + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
