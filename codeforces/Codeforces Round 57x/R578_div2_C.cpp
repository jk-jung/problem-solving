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
    ll n, m, q;
    cin >> n >> m >> q;
    ll g = gcd(n, m);
    ll a = n / g;
    ll b = m / g;
    while (q--) {
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        y1--, y2--;
        ll xx = x1 == 1 ? y1 / a : y1 / b;
        ll yy = x2 == 1 ? y2 / a : y2 / b;
        cout << (xx == yy ? "YES" : "NO") << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
