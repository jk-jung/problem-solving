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
    int n, q;
    cin >> n >> q;
    vi v(n);
    vi L(n + 1), R(n + 1, n + 1), s(n + 1);
    for (int &x: v)cin >> x;
    for (int i = 0; i < n; i++)s[i + 1] = s[i] ^ v[i];

    for (int i = 0, t = -1; i < n; i++) {
        if (v[i])t = i;
        L[i] = t;
        s[i + 1] = s[i] ^ v[i];
    }
    for (int i = n - 1, t = n; i >= 0; i--) {
        if (v[i])t = i;
        R[i] = t;
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        int ra = a, rb = b;
        int ss = s[b + 1] ^ s[a];
        if (R[a] > L[b]) {
            cout << a + 1 << " " << a + 1 << endl;
            continue;
        }
        a = R[a];
        b = L[b];
        int ta = a;
        for (int _ = 0; _ < 32 && ta <= b; _++) {
            int tb = b;
            int tss = ss;
            while (tb > ta && (tss & v[tb]) == v[tb]) {
                tss ^= v[tb];
                tb = L[tb - 1];
            }
            if (rb - ra > tb - ta) {
                ra = ta;
                rb = tb;
            }
            if ((v[ta] & ss) != v[ta]) break;
            ss ^= v[ta];
            ta = R[ta + 1];
        }
        cout << ra + 1 << " " << rb + 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
