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
    vector<ll> v;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            v.pb(i);
            if (i * i != n)v.pb(n / i);
        }
    }
    sort(v.begin(), v.end());
    if (v.size() < k)cout << -1 << endl;
    else cout << v[k - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
