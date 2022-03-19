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

    IndexTree(int _n) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        size = 1 << (32 - __builtin_clz(n));
        d.resize(size * 2 + 5);
    }

    void up(int x, int v) {
        x += size;
        int dif = v - d[x];
        while (x) d[x] += dif, x >>= 1;
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

    int find(int x) {
        int s = x, e = n - 1, r = -1;
        while (s <= e) {
            int m = (s + e) / 2;
            if (read(s, m) == m - s + 1)s = m + 1;
            else e = m - 1, r = m;
        }
        return r;
    }
};


void solve() {
    int n;
    cin >> n;
    vi v(n);

    set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(i);
        cin >> v[i];
    }

    IndexTree tre(n);

    for (int i = 1; i < n; i++) {
        int k = gcd(v[i - 1], v[i]) == 1 ? 0 : 1;
        tre.up(i, k);
    }

    int y = 0;
    vi r;
    while (true) {
        if (st.size() == 1)break;

        int z = tre.find(y + 1);

        int s = *st.begin();
        int e = *st.rbegin();
        if (z == -1) {
            int g = gcd(v[s], v[e]);
            if (g == 1) {
                r.pb(s);
                st.erase(s);
            }
            if (y == s && *st.begin() == y)break;
            y = *st.begin();
        } else {
            r.pb(z);

            tre.up(z, 1);
            st.erase(z);
            if (st.size() == 1)break;

            if (z == e) {
                y = s;
            } else {
                auto it = st.lower_bound(z);
                int z2 = *it;
                it--;
                int z1 = *it;
                int k = gcd(v[z1], v[z2]) == 1 ? 0 : 1;
                tre.up(z2, k);
                y = z2;
            }
        }
    }
    if (st.size() == 1 && v[*st.begin()] == 1) r.pb(*st.begin());

    cout << r.size() << ' ';
    for (int x: r)cout << x + 1 << " ";
    cout << '\n';
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
