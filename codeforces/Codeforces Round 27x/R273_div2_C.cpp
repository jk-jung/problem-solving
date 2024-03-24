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
    vector<ll> v(3);
    for (ll &x: v)cin >> x;
    sort(v.begin(), v.end());

    ll n = v.back();
    if (n >= (v[0] + v[1]) * 2) {
        cout << v[0] + v[1] << endl;
    } else {
        ll r = n / 2;
        ll a = v[0] + v[1] - r;
        if (n % 2 && a >= 2) a-=2, r++;
        cout << r + a / 3 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
