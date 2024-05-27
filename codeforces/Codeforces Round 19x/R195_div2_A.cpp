#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    ll a, b;
    cin >> a >> b;
    vector<pi> v;
    ll t = ab(a) + ab(b);
    v.pb({0, t * ab(b) / b});
    v.pb({t * ab(a) / a, 0});
    sort(v.begin(), v.end());
    for (auto [x, y]: v)cout << x << " " << y << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
