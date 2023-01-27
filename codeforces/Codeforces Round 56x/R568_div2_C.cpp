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
    int n, m, s = 0;
    cin >> n >> m;
    vi v(n);
    for (int &x: v)cin >> x;

    vi r;
    int cnt = 0;
    vi cc(101);
    for (int x: v) {
        int rest = m - x, tmp = 1;
        for (int i = 1; i <= 100; i++) {
            int can = min(cc[i], rest / i);
            tmp += can;
            rest -= can * i;
        }
        cnt++;
        r.pb(cnt - tmp);
        cc[x] ++;
    }
    for (int x: r)cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
