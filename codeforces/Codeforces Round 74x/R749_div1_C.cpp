#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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

class IndexTree {
public:
    int n, size;
    vector<int> d;

    void init(int _n) {
        n = _n;
        size = 1 << (32 - __builtin_clz(n));
        d.resize(size * 2 + 5);
    }

    void up(int x, int v) {
        x += size;
        while (x) d[x] += v, x >>= 1;
    }

    int read(int s, int e) {
        s += size, e += size;
        int r = 0;
        while (s <= e) {
            if ((s & 1) == 1) r += d[s++];
            if ((e & 1) == 0) r += d[e--];
            s >>= 1, e >>= 1;
        }
        return r;
    }

    int kth(int k) {
        int x = 1;
        while (x < size) {
            if (d[x * 2] < k) k -= d[x * 2], x = x * 2 + 1;
            else x *= 2;
        }
        return x - size;
    }
} tre;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];

    tre.init(m + 5);

    for (int i = 0; i < m - 1; i++) {
        for (int k = 1; k < n; k++) {
            if (v[k    ][i    ] != 'X') continue;
            if (v[k - 1][i + 1] != 'X') continue;
            if (v[k    ][i + 1] != '.') continue;

            tre.up(i, 1);
            break;
        }

        for (int k = 1; k < n; k++) {
            if (v[k    ][i    ] != 'X') continue;
            if (v[k - 1][i + 1] != 'X') continue;
            if (v[k    ][i + 1] != 'X') continue;

            tre.up(i, 1);
            break;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int s, e;
        cin >> s >> e;
        s--, e--;

        if (s == e) {
            cout << "YES\n";
            continue;
        }

        int c = tre.read(s, e - 1);
        cout << (c > 0 ? "NO\n" : "YES\n");
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
