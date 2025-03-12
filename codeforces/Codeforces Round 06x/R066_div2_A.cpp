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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<pair<ll, ll>> v = {{1, a},
                              {1, b},
                              {1, c}};
    while (d > 0) {
        sort(v.begin(), v.end());
        bool ok = false;
        for (int i = 0; i < 3; i++) {
            if (v[i].F < v[i].S) {
                v[i].F++;
                d--;
                ok = true;
                break;
            }
        }
        if (!ok)break;
    }
    cout << v[0].F * v[1].F * v[2].F << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
