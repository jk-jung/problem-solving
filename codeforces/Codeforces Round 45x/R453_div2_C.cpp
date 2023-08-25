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


void process(int n, int h, vi &v, bool flag = false) {
    int pos = 0, c = 0, last = 0;
    vi r;
    vector<vi> vv(h + 1);
    for (int i = 1; i <= n; i++) {
        r.pb(last);
        vv[pos].pb(i);
        if (++c == v[pos]) {
            pos++;
            c = 0;
            last = i;
        }
    }

    if (flag) {
        for (int i = 1; i < h; i++) {
            if (v[i - 1] > 1 && v[i] > 1) {
                r[vv[i][0] - 1] = vv[i - 1][1] - 1;
                break;
            }
        }
    }

    for (int x: r)cout << x << " ";
    cout << endl;
}

void solve() {
    int h, n = 0;
    cin >> h;
    h++;
    vi v(h);
    for (int &x: v)cin >> x, n += x;

    for (int i = 1; i < h; i++) {
        if (v[i - 1] > 1 && v[i] > 1) {
            cout << "ambiguous" << endl;
            process(n, h, v);
            process(n, h, v, true);
            return;
        }
    }
    cout << "perfect" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
