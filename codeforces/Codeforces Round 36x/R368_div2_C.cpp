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
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ll t = n * n / i;
            if (t - i > 0 && (t + i) % 2 == 0) {
                cout << (t + i) / 2 << " " << (t - i) / 2 << endl;
                return;
            }
            ll j = n / i;
            t = n * n / j;
            if (t - j > 0 && (t + j) % 2 == 0) {
                cout << (t + j) / 2 << " " << (t - j) / 2 << endl;
                return;
            }

        }
    }

    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
