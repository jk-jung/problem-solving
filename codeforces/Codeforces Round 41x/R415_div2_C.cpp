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
ll d[300005];

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());

    d[0] = 1;
    for (int i = 1; i < n; i++)d[i] = (d[i - 1] * 2) % mod;
    for (int i = 0; i < n; i++)d[i] = (d[i] - 1 + mod) % mod;

    ll r = 0;
    for (int i = 1; i < n; i++) {
        ll dif = v[i] - v[i - 1];
        r = (r + dif * d[i] % mod * d[n-i]) % mod;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
