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
    int cnt = 0;
    for (ll i = 1;; i++) {
        ll t = 0;
        ll x = i;
        bool ok = true;
        ll base = 1;
        while (x) {
            if (x % 3 == 0) {
                ok = false;
                break;
            }
            t += (x % 3 == 1 ? 4 : 7) * base;
            x /= 3;
            base *= 10;
        }
        if (ok) {
            cnt++;
            if (t == n) {
                cout << cnt << endl;
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
