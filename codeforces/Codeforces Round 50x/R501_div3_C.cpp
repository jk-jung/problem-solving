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
    ll n, m, t = 0;
    cin >> n >> m;
    vector<pair<ll, ll>> v(n);
    for (auto &[x, y]: v)cin >> x >> y, y = y - x, t += x, swap(x, y);
    sort(v.begin(), v.end());
    int r = 0;
    for (auto [x, _]: v) {
        if (t <= m)break;
        t += x;
        r++;
    }
    cout << (t <= m ? r : -1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
