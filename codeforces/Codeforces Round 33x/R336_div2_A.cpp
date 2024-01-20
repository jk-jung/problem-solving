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
    int n, s;
    cin >> n >> s;
    vector<pi> v(n);
    for (auto &x: v)cin >> x.F >> x.S;
    sort(v.rbegin(), v.rend());
    int r = 0;
    for (auto [x, y]: v) {
        r += s - x;
        r = max(r, y);

        s = x;
    }
    cout << r + s<< endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
