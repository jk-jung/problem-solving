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
    ll m = n * (n + 1) / 2;
    for (ll i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            cout << "Yes\n";
            cout << "1 " << i << endl;
            cout << n - 1;
            for (ll j = 1; j <= n; j++)if (j != i) cout << " " << j;
            cout << endl;
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
