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

int a, b;
int d[105][105][15][15];

int go(int n, int m, int p, int q) {
    if (n < 0 || m < 0 || p > a || q > b) return 0;
    if (n == 0 && m == 0)return 1;
    int &r = d[n][m][p][q];
    if (r != -1)return r;
    return r = (go(n - 1, m, p + 1, 0) + go(n, m - 1, 0, q + 1)) % 100000000;
}

void solve() {
    int n, m;
    cin >> n >> m >> a >> b;
    memset(d, -1, sizeof(d));
    cout << go(n, m, 0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
