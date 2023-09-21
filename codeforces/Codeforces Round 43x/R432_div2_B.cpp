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
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    ll x = (a - c) * (a - c) + (b - d) * (b - d);
    ll y = (c - e) * (c - e) + (d - f) * (d - f);
    if (x == y) {
        ll dx = a - c;
        ll dx2 = c - e;
        ll dy = b - d;
        ll dy2= d - f;
        if (dx == dx2 && dy == dy2) {
            cout << "No\n";
            return;
        }
    }
    cout << (x == y ? "Yes" : "No") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
