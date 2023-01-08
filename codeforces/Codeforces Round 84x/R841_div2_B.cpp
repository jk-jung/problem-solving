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


ll mod = 1000000007;
void solve() {
    ll n;
    cin >> n;
    ll a = n, b = n + 1, c = 2 * n + 1;
    if (a % 3 == 0) a /= 3;
    else if (b % 3 == 0)b /= 3;
    else c /= 3;
    ll r = (a * b % mod * c % mod - n * (n + 1) / 2 % mod + mod) % mod;
    cout << (r % mod * 2022) % mod << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
