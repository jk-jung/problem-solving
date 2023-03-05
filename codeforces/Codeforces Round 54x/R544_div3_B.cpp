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
    int n, k;
    cin >> n >> k;
    vector<ll> v(n), c(k);
    for (ll &x: v)cin >> x, c[x % k]++;
    ll r = 0;
    for (ll i = 0; i < k; i++) {
        ll j = (k - i) % k;
        if (i < j)r += min(c[i], c[j]);
        else if (i == j) r += c[i] / 2;
    }
    cout << r * 2<< endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
