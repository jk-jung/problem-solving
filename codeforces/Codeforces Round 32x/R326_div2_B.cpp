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

bool f(ll x) {
    for (ll y = 2; y * y <= x; y++) {
        if (x % (y * y) == 0)return false;
    }
    return true;
}

void solve() {
    ll n;
    cin >> n;
    ll r = 1;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (f(i))r = max(r, i);
            if (f(n / i))r = max(r, n / i);
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
