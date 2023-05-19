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
    vector<pair<ll, ll>> v(n), t;
    for (auto &[a, b]: v) {
        cin >> a >> b;
        t.pb({a, -1});
        t.pb({b, +1});
    }
    vector<ll> r(n + 1);
    sort(t.begin(), t.end());

    ll st = 0, last = 0;
    for (int i = 0; i < t.size();) {
        ll x = t[i].F;
        r[st] += x - last - 1;
        while (i < t.size() && t[i].F == x && t[i].S == -1)st++, i++;
        r[st] ++;
        while (i < t.size() && t[i].F == x && t[i].S == +1)st--, i++;
        last = x;
    }

    for (int i = 1; i <= n; i++)cout << r[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
