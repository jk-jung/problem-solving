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

int u[255][255];

void solve() {
    string a, b;
    cin >> a >> b;
    map<char, char> c;
    for (int i = 0; i < a.size(); i++) {
        if (c.count(a[i]) && c[a[i]] != b[i]) {
            cout << -1 << endl;
            return;
        }
        if (c.count(b[i]) && c[b[i]] != a[i]) {
            cout << -1 << endl;
            return;
        }
        c[a[i]] = b[i];
        c[b[i]] = a[i];
    }
    vector<pair<char, char>> r;
    for (auto [x, y]: c) {
        if (u[x][y])continue;
        if(x == y)continue;
        u[y][x] = 1;
        r.pb({x, y});
    }
    cout << r.size() << endl;
    for (auto [x, y]: r) {
        cout << x << " " << y << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
