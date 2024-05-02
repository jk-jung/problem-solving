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
int n, k;
int a[105], b[105];

map<int, int> d[100][2];

int go(int i, int x, int used=0) {
    if (i == n) return used && x == 0 ? 0 : -1e9;
    if (d[i][used].count(x)) return d[i][used][x];
    int r = max(go(i + 1, x, used),
                go(i + 1, x + b[i] * k - a[i], 1) + a[i]);
    return d[i][used][x] = r;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i];

    cout << max(-1, go(0, 0)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
