#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
    string s;
    cin >> s;
    map<pi, int> t;
    int y = 0, x = 0;
    t[{y, x}] = 1;
    for (char c: s) {
        int a = y, b = x;
        if (c == 'U') y--;
        if (c == 'D') y++;
        if (c == 'L') x--;
        if (c == 'R') x++;
        if (t.count({y, x})) {
            cout << "BUG";
            return;
        }
        t[{y, x}] = 1;

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (ny == a && nx == b)continue;
            if (t.count({ny, nx})) {
                cout << "BUG";
                return;
            }
        }
    }
    cout << "OK";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
