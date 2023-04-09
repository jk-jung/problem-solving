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
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (i == 2) {
                cout << n / i << endl;
            } else {
                ll t = n - i;
                if (t % 2 == 0)cout << 1 + t / 2 << endl;
                else cout << 2 + (t - i) / 2 << endl;
            }
            return;
        }
    }
    cout << 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
