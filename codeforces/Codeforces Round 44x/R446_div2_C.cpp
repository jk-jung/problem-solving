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
    vi v(n);
    int r = -1, o = 0;
    for (int &x: v)cin >> x, o += x == 1;

    if (o) {
        r = n - o;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = i, g = 0; j < n; j++) {
                g = gcd(g, v[j]);
                if (g == 1) {
                    int t = j - i + n - 1;
                    if (r == -1)r = t;
                    else r = min(r, t);
                }
            }
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
