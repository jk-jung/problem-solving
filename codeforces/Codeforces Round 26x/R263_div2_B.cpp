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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<int, ll> c;
    for (char x: s)c[x]++;
    ll r = 0;
    vector<ll> v;
    for (auto x: c)v.pb(x.S);
    sort(v.rbegin(), v.rend());
    for (ll x: v) {
        ll t = min(k, x);
        r += t * t;
        k -= t;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
