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
    vi v(n + 2);
    for (int i = 1; i <= n; i++)cin >> v[i];
    v[n + 1] = m;

    int r = 0, s = 0, e = 0;

    for (int i = 1; i < n + 2; i += 2)
        r += v[i] - v[i - 1];

    for (int i = 2; i < n + 2; i += 2)
        e += v[i] - v[i - 1];
    for (int i = 2; i < n + 2; i += 2) {
        s += v[i - 1] - v[i - 2];
        int dif = v[i] - v[i - 1];
        e -= dif;
        if (dif > 1) {
            r = max(r, s + e + dif - 1);
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
