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

map<int, vi> ck;
map<int, vi> ss;

void solve() {
    int n;
    cin >> n;
    for (int a, b, i = 0; i < n; i++) {
        cin >> a >> b;
        ck[a].pb(b);
    }
    for (auto&[k, v]: ck) {
        sort(v.begin(), v.end());
        vi s(v.size());
        s[0] = v[0];
        for (int i = 1; i < v.size(); i++) s[i] = s[i - 1] + v[i];
        ss[k] = s;
    }
    ll r1 = 0, r2 = 1;
    vi rv;

    vector<pi> t(ck.size());
    for (int i = 1; i <= min(40, (int) ck.size()); i++) {
        int j = 0;
        for (auto&[k, v]: ck) {
            int pos = int(lower_bound(v.begin(), v.end(), i) - v.begin());
            int s = pos == 0 ? 0 : ss[k][pos - 1];
            s += ((int) v.size() - pos) * i;
            t[j].F = -s;
            t[j].S = k;
            j++;
        }
        sort(t.begin(), t.end());
        ll r3 = 0, r4 = i;
        vi rv2;
        for (int j = 0; j < i; j++)r3 -= t[j].F, rv2.pb(t[j].S);
        if (r3 * r2 > r1 * r4) {
            r1 = r3;
            r2 = r4;
            rv = rv2;
        }
    }

    cout << rv.size() << endl;
    for (int x: rv)cout << x << " ";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
