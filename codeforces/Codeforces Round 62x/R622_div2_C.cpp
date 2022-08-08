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


int n;

vector<ll> calc(vi v) {
    vector<ll> r(n);

    stack<tuple<int, int, ll>> st;
    r[0] = v[0];
    st.push({0, -1, 0ll});
    st.push({v[0], 0, r[0]});
    for (int i = 1; i < n; i++) {
        while (get<0>(st.top()) >= v[i])
            st.pop();

        auto [_, idx, val] = st.top();
        ll cost = val + (i - idx) * (ll) v[i];
        st.push({v[i], i, cost});
        r[i] = cost;
    }
    return r;
}

void solve() {
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    vector<ll> a = calc(v);
    reverse(v.begin(), v.end());
    vector<ll> b = calc(v);
    reverse(b.begin(), b.end());
    reverse(v.begin(), v.end());
    ll r = 0;
    int r_idx = 0;
    for (int i = 0; i < n; i++) {
        ll t = a[i];
        if (i + 1 < n) t += b[i + 1];
        if (t > r) {
            r = t;
            r_idx = i;
        }
    }

    vi rst(n);
    rst[r_idx] = v[r_idx];
    if (r_idx + 1 < n)rst[r_idx + 1] = v[r_idx + 1];
    for (int i = r_idx - 1; i >= 0; i--)rst[i] = min(v[i], rst[i + 1]);
    for (int i = r_idx + 2; i < n; i++)rst[i] = min(v[i], rst[i - 1]);
    for (int x: rst)cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
