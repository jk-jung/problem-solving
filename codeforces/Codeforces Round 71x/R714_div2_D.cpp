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
        d[x] = v;
        x /= 2;
        while (x) {
            d[x] = gcd(d[x * 2], d[x * 2 + 1]);
            x >>= 1;
        }
    }

    int read(int s, int e) {
        s += size, e += size;
        int r = d[s];
        while (s <= e) {
            if ((s & 1) == 1) r = gcd(r, d[s++]);
            if ((e & 1) == 0) r = gcd(r, d[e--]);
            s >>= 1, e >>= 1;
        }
        return r;
    }

    int find_right(int k) {
        int s = k, e = n - 1, r = k;
        int v = d[s + size];
        while (s <= e) {
            int m = (s + e) / 2;
            if (read(k, m) == v) s = m + 1, r = m;
            else e = m - 1;
        }
        return r;
    }

    int find_left(int k) {
        int s = 0, e = k, r = k;
        int v = d[e + size];
        while (s <= e) {
            int m = (s + e) / 2;
            if (read(m, k) == v) e = m - 1, r = m;
            else s = m + 1;
        }
        return r;
    }
};

void solve() {
    int n, p;
    cin >> n >> p;
    vi v(n), used(n);
    vector<pi> t(n);
    set<int> st;
    IndexTree tre(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        t[i] = {v[i], i};
        st.insert(i);
        tre.up(i, v[i]);
    }
    sort(t.begin(), t.end());

    ll r = 0;
    int cnt = 0;
    for (auto[x, idx]: t) {
        if (x >= p)break;
        int s = tre.find_left(idx);
        int e = tre.find_right(idx);

        if(used[idx] == 0){
            if (s != idx && used[s]) { r += x, cnt++; }
            if (e != idx && used[e]) { r += x, cnt++; }
        }

        vi er;
        auto it = st.lower_bound(s);
        while (it != st.end() && *it <= e) {
            if (*it != idx) {
                r += x;
                cnt++;
            }
            er.pb(*it);
            used[*it] = 1;
            it++;
        }
        for (int y: er)st.erase(y);
    }
    while(cnt < n - 1) r += p, cnt ++;
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
