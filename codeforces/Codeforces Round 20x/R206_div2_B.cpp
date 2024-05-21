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

int a, b, c, d;

int f(vi &v) {
    int r = c;
    int s = 0;
    for (int x: v) {
        s += min(x * a, b);
    }

    return min(r, s);
}

void solve() {
    cin >> a >> b >> c >> d;
    int n, m;
    cin >> n >> m;
    vi v1(n), v2(m);
    for (int &x: v1)cin >> x;
    for (int &x: v2)cin >> x;

    int r = d;
    r = min(r, f(v1) + f(v2));
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
