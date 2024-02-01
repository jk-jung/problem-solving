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
    int n, d;
    cin >> n >> d;
    vector<pi> v(n);
    for (auto &[x, y]: v)cin >> x >> y;

    ll r = 0, c = 0;
    queue<pi> q;
    sort(v.begin(), v.end());
    for (auto x: v) {
        q.push(x);
        c += x.S;
        while (x.F - q.front().F >= d) {
            c -= q.front().S;
            q.pop();
        }
        r = max(r, c);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
