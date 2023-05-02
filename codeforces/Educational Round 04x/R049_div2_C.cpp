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


bool f(pi a, pi b) {
    ll a1 = a.F * a.F + a.S * a.S;
    ll a2 = a.F * a.S;
    ll b1 = b.F * b.F + b.S * b.S;
    ll b2 = b.F * b.S;
    return a1 * b2 > b1 * a2;
}

void solve() {
    // xy
    // 4(x2 + 2xy + y2)
    // 8 +  (4x2 + 4y2) / xy
    // x/y + y


    int n;
    cin >> n;
    vi v(n), t;
    map<int, int> ck;
    for (int &x: v) {
        cin >> x;
        if (++ck[x] == 2) {
            t.pb(x);
            ck[x] = 0;
        }
    }
    sort(t.begin(), t.end());
    pi r = {1, 10000};
    for (int i = 1; i < t.size(); i++) {
        if (f(r, mp(t[i - 1], t[i]))) r = mp(t[i-1], t[i]);
    }
    cout << r.F << " " << r.F << " " << r.S << " " << r.S << endl;
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
