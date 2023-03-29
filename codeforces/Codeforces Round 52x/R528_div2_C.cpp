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

vector<pi> v(3);
vector<pi> dd = {{0,  1},
                 {1,  0},
                 {0,  -1},
                 {-1, 0}};
int d[1005][1005];

int dis(int x, int y) {
    int r = 0;
    for (int i = 1; i < 3; i++)r += ab(v[i].F - x) + ab(v[i].S - y);
    return r;
}

void go(pi a, pi b) {
    while (a.F < b.F) cout << a.F++ << " " << a.S << endl;
    while (a.F > b.F) cout << a.F-- << " " << a.S << endl;
    while (a.S < b.S) cout << a.F << " " << a.S++ << endl;
    while (a.S > b.S) cout << a.F << " " << a.S-- << endl;
}

void solve() {
    memset(d, 63, sizeof(d));
    for (auto &[x, y]: v)cin >> x >> y;

    queue<pi> q;
    d[v[0].F][v[0].S] = 1;
    q.push(v[0]);

    int r = 1 << 30;
    pi rr;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        int t = d[x][y] + dis(x, y);
        if (t < r) {
            r = t;
            rr = {x, y};
        }
        for (auto [dx, dy]: dd) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || ny < 0 || nx > 1000 || ny > 1000 || d[nx][ny] <= d[x][y] + 1)continue;
            if(d[nx][ny] < 3000) {
                r = r;
            }
            d[nx][ny] = d[x][y] + 1;
            q.push({nx, ny});
        }
    }
    cout << r << endl;
    cout << rr.F << " " << rr.S << endl;
    for (auto x: v)go(x, rr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
