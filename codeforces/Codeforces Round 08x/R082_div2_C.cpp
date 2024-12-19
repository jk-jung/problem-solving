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

int d[1005];

void solve() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    for (int i = p; i <= n; i++)d[i] = d[i - p] + q;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b >> p >> q;
        int cnt = a / b;

        while (cnt--) {
            for (int k = n; k >= p; k--)
                d[k] = max(d[k], d[k - p] + q);
        }
    }
    cout << d[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
