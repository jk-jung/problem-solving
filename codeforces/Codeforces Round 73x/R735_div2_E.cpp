#include <string.h>
#include <stdio.h>
#include <math.h>
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

const int mod = 998244353;
int n;
vector<int> v[100005];
map<int, int> d[100005][2];

int mul(int x, int y) { return int((ll) x * y % mod); }

int add(int x, int y) { return int(((ll) x + y) % mod); }


map<int, int> go(int x, int p, int k) {
    auto &r = d[x][k];
    if (!r.empty()) return r;

    map<pi, int> ck;
    ck[{k, 0}] = 1;
    for (auto y: v[x]) {
        if (y == p) continue;

        map<pi, int> ck2;
        for (int i = 0; i < 2; i++) {
            auto sub = go(y, x, i);

            for (auto t1 : sub) {
                for (auto t2: ck) {
                    int s = t2.F.F + 1 - i;
                    int g = gcd(t2.F.S, t1.F);
                    int c = mul(t2.S, t1.S);
//                    if (g == 1) s = 0;
                    ck2[{s, g}] = add(ck2[{s, g}], c);
                }
            }
        }
        ck = ck2;
    }

    for (auto t : ck) {
        int g = gcd(t.F.F, t.F.S);
        r[g] = add(r[g], t.S);
    }
    return r;
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int s, e;
        cin >> s >> e;
        v[s].pb(e);
        v[e].pb(s);
    }

    auto r = go(1, -1, 0);
    for (int i = 1; i <= n; i++) cout << r[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++){
        v[i].clear();
        d[i][0].clear();
        d[i][1].clear();
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
