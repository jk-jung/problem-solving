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
    ll n;
    cin >> n;
    ll r = 0;
    for (ll i = 1; i < 10000; i++) {
        ll t = 0;
        for (ll j = 0, x = 1; j < 20; j++, x *= 10) {
            if (i >> j & 1)t += x;
        }
        if (t <= n){
            r++;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
