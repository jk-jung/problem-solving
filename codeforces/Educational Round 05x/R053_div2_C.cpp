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
    string v;
    int tx, ty;
    cin >> n >> v >> tx >> ty;
    int s = 0, e = n, r = -1;
    int sx = 0, sy = 0;
    for (char c: v) {
        if (c == 'U') sy++;
        if (c == 'D') sy--;
        if (c == 'L') sx--;
        if (c == 'R') sx++;
    }
    while (s <= e) {
        int m = (s + e) / 2;
        queue<int> q;
        int x = sx;
        int y = sy;
        bool ok = false;
        for (char t: v) {
            q.push(t);
            if (t == 'U') y--;
            if (t == 'D') y++;
            if (t == 'L') x++;
            if (t == 'R') x--;

            if (q.size() > m) {
                int c = q.front();
                if (c == 'U') y++;
                if (c == 'D') y--;
                if (c == 'L') x--;
                if (c == 'R') x++;
                q.pop();
            }
            if (q.size() == m) {
                int dx = ab(x - tx);
                int dy = ab(y - ty);
                if (dx + dy <= m && (m - (dx + dy)) % 2 == 0)
                    ok = true;
            }
        }
        if (ok) { r = m, e = m - 1; }
        else s = m + 1;

    }

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
