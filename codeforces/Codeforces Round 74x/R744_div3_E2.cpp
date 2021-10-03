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
    int n, sz;
    vi v;

    IndexTree(int _n) {
        n = _n;
        for (sz = 1; sz < n; sz *= 2);
        v.resize(sz * 2 + 5);
    }

    void up(int x) {
        x += sz;
        while (x) v[x]++, x /= 2;
    }

    int read(int s, int e) {
        s += sz, e += sz;
        int r = 0;
        while (s <= e) {
            if (s % 2 == 1) r += v[s++];
            if (e % 2 == 0) r += v[e--];
            s /= 2, e /= 2;
        }
        return r;
    }
};

void solve() {
    int n;
    cin >> n;
    vi v(n), u(n);
    for (int i = 0; i < n; i++)cin >> u[i], v[i] = u[i];
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());

    IndexTree tre(u.size());
    ll r = 0;
    for (int x: v) {
        int i = lower_bound(u.begin(), u.end(), x) - u.begin();
        r += min(tre.read(0, i - 1), tre.read(i + 1, u.size() - 1));
        tre.up(i);
    }
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
