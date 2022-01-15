#include <string.h>
#include <stdio.h>
#include <math.h>
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

vector<pi> valid;

class IndexTree {
public:
    int n, size;
    vector<vi> d;

    IndexTree(int _n) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        size = 1 << (32 - __builtin_clz(n));
        d.resize(size * 2 + 5, vi(32));
    }

    int up(int x, int v) {
        x += size;
        for (int i = 0; i < 32; i++) d[x][i] = 1 << 30;
        for (int i = 0; i < 3; i++) d[x][1 << i] = 1;
        d[x][1 << v] = 0;
        x >>= 1;

        while (x) {
            int l = x * 2;
            int r = x * 2 + 1;
            for (int i = 0; i < 32; i++) d[x][i] = 1 << 30;

            for(auto[i, j]: valid) {
                if (d[l][i] == 1 << 30) continue;
                if (d[r][j] == 1 << 30) continue;

                int nt = i | j;
                if ((i >> 0 & 1) && (j >> 1 & 1)) nt |= 1 << 3;
                if ((i >> 1 & 1) && (j >> 2 & 1)) nt |= 1 << 4;

                d[x][nt] = min(d[x][nt], d[l][i] + d[r][j]);
            }

            x >>= 1;
        }

        int rst = 1 << 30;
        for (int i = 0; i < 32; i++)rst = min(rst, d[1][i]);
        return rst;
    }
};

void solve() {
    int n, q;
    string s;
    cin >> n >> q >> s;

    IndexTree tre(n);
    for (int i = 0; i < n; i++) tre.up(i, s[i] - 'a');

    while (q--) {
        int x;
        char c;
        cin >> x >> c;
        cout << tre.up(x - 1, c - 'a') << '\n';
    }

}


bool is_valid(int x) {
    if ((x >> 3 & 1) && !((x >> 0 & 1) && (x >> 1 & 1))) return false;
    if ((x >> 4 & 1) && !((x >> 1 & 1) && (x >> 2 & 1))) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt = 0;

    for (int i = 1; i < 32; i++) {
        if (!is_valid(i))continue;
        for (int j = 1; j < 32; j++) {
            if (!is_valid(j))continue;
            if ((i >> 0 & 1) && (j >> 4 & 1)) continue;
            if ((i >> 3 & 1) && (j >> 2 & 1))continue;

            valid.pb({i, j});
        }
    }

    solve();
}
