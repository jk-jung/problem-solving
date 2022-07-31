#include <string.h>
#include <stdio.h>
#include <math.h>
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
    for (auto &[x, y]: v)cin >> x >> y;
    map<pi, int> ck;
    for (int i = 0; i < n; i++) {
        auto [x0, y0] = v[i];
        auto [x1, y1] = v[(i + 1) % n];

        int dx = x1 - x0;
        int dy = y1 - y0;
        if (dx == 0 || dy == 0)ck[{ab(dx), ab(dy)}]++;
        else {
            if (dx < 0)dx = -dx, dy = -dy;
            ck[{dx, dy}]++;
        }
    }
    for(auto [p, cnt]: ck) {
        if(cnt % 2) {
            cout <<"NO\n";
            return;
        }
    }
    cout <<"YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
