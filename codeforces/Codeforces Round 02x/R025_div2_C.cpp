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


int d[333][333];

void solve() {
    int n, q;
    cin >> n;
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> d[i][j];
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    cin >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        d[a][b] = d[b][a] = min(d[a][b], c);
        vi v(2);
        v[0] = a;
        v[1] = b;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], min(
                        d[i][a] + d[b][j] + d[a][b],
                        d[i][b] + d[a][j] + d[a][b]
                ));
            }
        ll r = 0;
        for (int i = 0; i < n; i++)for (int j = 0; j < i; j++)r += d[i][j];
        cout << r << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
