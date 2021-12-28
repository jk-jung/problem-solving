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
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll &x: v)cin >> x;

    ll a = 0, b = 0;
    for (int i = 0; i < n; i += 2) a = gcd(a, v[i]);
    for (int i = 1; i < n; i += 2) b = gcd(b, v[i]);
    for (int i = 0; i < n; i += 2)if (v[i] % b == 0) { b=0; break; }
    for (int i = 1; i < n; i += 2)if (v[i] % a == 0) { a=0; break; }

    a = max(a, b);
    cout << a << '\n';
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
