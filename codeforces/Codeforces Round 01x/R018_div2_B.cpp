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
    ll n, d, m, l, pos = 0;
    cin >> n >> d >> m >> l;


    for (ll i = 0; i < n; i++) {
        ll s = i * m;
        ll e = i * m + l;
        if (pos < s)break;
        if (pos <= e) {
            ll need = (e - pos + d) / d * d;
            pos += need;
        }
    }
    cout << pos << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
