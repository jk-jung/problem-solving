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
    ll a, b;
    cin >> a >> b;
    for (ll x = a; x <= b; x++) {
        for (ll y = x + 1; y <= b; y++) {
            for (ll z = y + 1; z <= b; z++) {
                if (gcd(x, y) == 1 && gcd(y, z) == 1 && gcd(x, z) != 1) {
                    cout << x << ' ' << y << ' ' << z << endl;
                    return;
                }
            }
        }
    }
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
