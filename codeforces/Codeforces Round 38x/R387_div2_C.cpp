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

struct Data {
    int a, b, c;
};


void solve() {
    int n, q;
    cin >> n >> q;
    vector<Data> v(q + 1);
    vector<pi> t;
    for (int i = 1; i <= q; i++) {
        cin >> v[i].a >> v[i].b >> v[i].c;
        t.pb({v[i].a, i});
        t.pb({v[i].a + v[i].c, -i});
    }
    sort(t.begin(), t.end());

    vi r(q + 1, -1);
    vi sv(n + 1);
    int st = n;
    for (int i = 0; i < t.size();) {
        int x = t[i].F;
        while (t[i].F == x) {
            int idx = t[i].S;
            int need = v[ab(idx)].b;
            if (idx > 0 && st >= need) {
                st -= v[idx].b;
                r[idx] = 0;

                for (int j = 1; j <= n; j++)if (!sv[j] && need)r[idx] += j, sv[j] = idx, need--;
            }
            if (idx < 0) {
                for (int j = 1; j <= n; j++) {
                    if (sv[j] == -idx) {
                        st++;
                        sv[j] = 0;
                    }
                }
            }
            i++;
        }
    }
    for (int i = 1; i <= q; i++)cout << r[i] << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
