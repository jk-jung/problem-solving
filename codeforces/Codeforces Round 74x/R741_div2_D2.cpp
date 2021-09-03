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

int s1[300005];
int s2[300005];

void solve() {
    int n, q;
    string v;
    cin >> n >> q >> v;

    for (int i = 0, ck = 1; i < n; i++, ck *= -1) {
        int k = v[i] == '+' ? 1 : -1;
        s1[i + 1] = s1[i] + k * ck;
    }

    s2[n + 1] = 0;
    for (int i = n - 1, ck = n % 2 ? 1 : -1; i >= 0; i--, ck *= -1) {
        int k = v[i] == '+' ? 1 : -1;
        s2[i + 1] = s2[i + 2] + k * ck;
    }

    map<int, vector<int>> t;
    for (int i = 1; i <= n; i++) {
        int k = s1[i - 1] - s2[i + 1];
        t[k].pb(i);
    }

    while (q--) {
        int L, R;
        vi r;
        cin >> L >> R;
        if (s1[R] - s1[L - 1] != 0) {
            if ((R - L + 1) % 2 == 0)r.pb(R--);
            int k = s1[L - 1] - s2[R + 1];
            vi &tt = t[k];
            int idx = lower_bound(tt.begin(), tt.end(), L) - tt.begin();
            r.pb(tt[idx]);
        }
        cout << r.size() << '\n';
        for (int x : r)cout << x << ' ';
        cout << '\n';
    }

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
