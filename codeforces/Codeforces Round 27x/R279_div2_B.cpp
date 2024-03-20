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


void solve() {
    int n;
    cin >> n;
    map<int, int> c, cc, f;
    while (n--) {
        int a, b;
        cin >> a >> b;
        c[a] = b;
        cc[a]++;
        cc[b]++;
        f[a] = 1;
    }
    vector<vi> rr;
    for (auto [x, t]: cc)
        if ((t == 1 || x == 0) && f[x] == 1) {
            int r = x;
            vi r1;
            r1.pb(r);
            while (c.count(r)) {
                r1.pb(c[r]);
                r = c[r];
                if(r == 0)break;
            };
            rr.pb(r1);
        }
    sort(rr.begin(), rr.end());
    vi &a = rr[0];
    vi &b = rr[1];
    for (int i = 0; i < max(a.size(), b.size()); i++) {
        if(i < a.size() && a[i])cout << a[i] << " ";
        if(i < b.size() && b[i] )cout << b[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
