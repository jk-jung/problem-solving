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
    vi v(n), u(n);
    for (int &x: v)cin >> x;

    vector<vi> r;
    while (true) {
        vi c(3 + 1);
        for (int i = 0; i < n; i++) {
            if (!c[1] && v[i] == 1 && u[i] == 0) u[i] = 1, c[1] = i + 1;
            if (!c[2] && v[i] == 2 && u[i] == 0) u[i] = 1, c[2] = i + 1;
            if (!c[3] && v[i] == 3 && u[i] == 0) u[i] = 1, c[3] = i + 1;
        }
        if (c[1] && c[2] && c[3]) {
            r.pb({c[1], c[2], c[3]});
        } else break;
    }
    cout << r.size() << endl;
    for (vi &v: r) {
        for (int x: v)cout << x << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
