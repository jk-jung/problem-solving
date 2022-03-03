#include <string.h>
#include <stdio.h>
#include <math.h>
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
    int n, t, c = 0;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    t = v[0];
    for (int x: v)t &= x;
    for (int x: v)if (x == t)c++;

    if (c < 2) {
        cout << 0 << endl;
    } else {
        ll mod = 1000000007;
        ll r = (ll) c * (c - 1) % mod;
        for(int i=2;i<=n-2;i++)r = (r * i) % mod;
        cout << r << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
