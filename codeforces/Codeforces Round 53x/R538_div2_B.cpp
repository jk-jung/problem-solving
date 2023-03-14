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
    int n, m, k;
    cin >> n >> m >> k;
    vi v(n), t;
    for (int &x: v)cin >> x;
    t = v;
    map<int, int> ck;
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());

    ll r = 0;
    for (int i = 0; i < m * k; i++)ck[t[i]]++, r += t[i];
    cout << r << endl;

    vi tt;
    for (int i = 0, cur = 0; i < n; i++) {
        if (ck[v[i]] > 0) {
            cur++;
            ck[v[i]]--;
        }
        if (cur == m) {
            tt.pb(i + 1);
            cur = 0;
        }
    }
    tt.pop_back();
    for (int x: tt)cout << x <<" ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
