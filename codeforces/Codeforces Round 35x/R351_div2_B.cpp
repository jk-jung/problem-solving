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
    int n, m;
    cin >> n >> m;
    vi r(n + 1);
    int a = -(1 << 30);
    int b = 1 << 30;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        if (x > y)swap(x, y);
        if (r[x] == 2 || r[y] == 1) {
            cout << 0;
            return;
        }
        r[x] = 1;
        r[y] = 2;
        a = max(a, x);
        b = min(b, y);
    }
    if (a < 0)cout << n - 1;
    else if (a > b)cout << 0;
    else cout << b - a;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
