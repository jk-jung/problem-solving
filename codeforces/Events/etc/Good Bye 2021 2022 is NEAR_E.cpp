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

class IndexTree {
public:
    int n, size;
    vector<int> d;

    IndexTree(int _n = 1) {
        init(_n);
    }

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

    int find(int k = 1) {
        int x = 1;
        while (x < size) {
            if (d[x * 2] < k) k -= d[x * 2], x = x * 2 + 1;
            else x *= 2;
        }
        x -= size;
        if(x >= n) return -1;
        return x;
    }
};

void solve() {
    int n;
    string a, b;
    cin >> n;
    cin >> a >> b;

    vi used(n);
    IndexTree tre[26], ss(n);
    for (auto &t: tre)t.init(n);
    for (int i = 0; i < n; i++)
        tre[a[i] - 'a'].up(i, 1);


    ll r = 1ll << 60;
    ll cur = 0;
    int a_i = 0;

    for (int i = 0; i < n; i++) {
        while (a_i < n && used[a_i]) a_i++;

        int ch = b[i] - 'a';
        for (int k = 0; k < ch; k++) {
            int ii = tre[k].find();
            if(ii == -1)continue;
            int need = ii - a_i - ss.read(a_i, ii);
            r = min(r, cur + need);
        }

        int idx = tre[ch].find();
        if (idx == -1) break;

        cur += idx - a_i - ss.read(a_i, idx);
        used[idx] = 1;
        ss.up(idx, 1);
        tre[ch].up(idx, -1);
    }


    if (r == (1ll << 60))r = -1;
    cout << r << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
