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
    vi v(n);
    for (int &x: v)cin >> x;

    ll a = 0, b = 0;
    string ss, tt;
    for (int i = 0; i < n; i++) {
        string s, t;
        cin >> s;
        t = s;
        reverse(t.begin(), t.end());

        if(i == 0)a = 0, b = v[i];
        else {
            ll aa = 1e18, bb = 1e18;
            if (s >= ss) aa = a;
            if (s >= tt) aa = min(aa, b);
            if (t >= ss) bb = a + v[i];
            if (t >= tt) bb = min(bb, b + v[i]);
            a = aa;
            b = bb;
        }
        ss = s;
        tt = t;
    }
    a = min(a, b);
    cout << (a >= 1e18 ? -1 : a) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
