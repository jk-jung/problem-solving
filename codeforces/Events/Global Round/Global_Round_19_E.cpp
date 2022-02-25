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

vi cnt[300005];

void solve() {
    int n, m;
    cin >> n >> m;
    vi v(n);
    for (int &x: v)cin >> x;
    map<pi, int> ck;
    while (m--) {
        int a, b;
        cin >> a >> b;
        ck[{a, b}] = 1;
    }

    map<int, int> cc;
    for (int x: v)cc[x]++;

    vi t;
    for (auto[k, x]: cc) cnt[x].pb(k);
    for (int i = 1; i <= n; i++) {
        if (!cnt[i].empty()) {
            sort(cnt[i].begin(), cnt[i].end());
            reverse(cnt[i].begin(), cnt[i].end());
            t.pb(i);
        }
    }

    ll r = 0;
    for (int i = 0; i < t.size(); i++) {
        for (int j = i; j < t.size(); j++) {
            int c1 = t[i];
            int c2 = t[j];
            vi &v1 = cnt[c1];
            vi &v2 = cnt[c2];
            for (int a = 0; a < v1.size(); a++) {
                int b = (c1 == c2 ? a + 1 : 0);
                for (; b < v2.size(); b++) {
                    int x = v1[a];
                    int y = v2[b];

                    ll val = ((ll) c1 + c2) * ((ll) x + y);
                    if (val <= r)break;
                    if (x > y)swap(x, y);
                    if (ck.count({x, y})) {
                        ck.erase({x, y});
                        continue;
                    }
                    r = max(r, val);
                    break;
                }
            }
        }
    }

    cout << r << endl;


    for (int i = 1; i <= n; i++)cnt[i].clear();

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
