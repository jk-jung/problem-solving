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
    map<int, int> ck;
    for (int &x: v)cin >> x;
    for (int i = 0; i < n; i++) {
        if (v[i] >= 10)ck[i] = v[i];
    }

    while (q--) {
        int op, x, y;
        cin >> op >> x;
        if (op == 1) {
            cin >> y;
            x--, y--;
            auto it = ck.lower_bound(x);
            vi re;
            while (it != ck.end() && it->F <= y) {
                int t = it->S, k = 0;
                while (t)k += t % 10, t /= 10;
                it->S = k;
                v[it->F] = k;
                if (k < 10)re.pb(it->F);
                it++;
            }
            for (int k: re)ck.erase(k);
        } else {
            cout << v[x - 1] << '\n';
        }
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
