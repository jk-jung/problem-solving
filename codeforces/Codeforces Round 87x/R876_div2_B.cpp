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
    vector<pi> v(n);
    for (auto &[x, y]: v) {
        cin >> x >> y;
        y = -y;
    }
    sort(v.begin(), v.end());
    ll t = 0, r = 0;
    queue<int> q;
    for (auto [x, y]: v) {
        if (x <= t)continue;
        r -= y;
        q.push(x);
        t = max(t, (ll) q.size());
        while (!q.empty() && q.front() <= t)q.pop();
    }
    cout << r << endl;
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
