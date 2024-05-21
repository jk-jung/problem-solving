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

void solve() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    vi v(n + 1);
    int s = 0;
    for (int &x: v)cin >> x, s += x;

    int r = 1 << 30, k = 0;
    for (int i = 0; i <= n; i++) {
        int t = k * a + s * b;
        int dif = max(0, ab(n - i - i) - 1);

        if(i > n / 2) t += dif * c;
        else t += dif * d;
        k += v[i];
        s -= v[i];
        r = min(r, t);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
