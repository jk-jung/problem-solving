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
    ll n;
    cin >> n;
    ll s = n * (n + 1) / 2;
    ll t = s / 2;
    vi r;
    for (ll i = n; i >= 1; i--) {
        if (i <= t)r.pb(i), t -= i;
    }
    cout << s - (s / 2) - (s / 2) << endl;
    cout << r.size() << " ";
    for (int x: r)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
