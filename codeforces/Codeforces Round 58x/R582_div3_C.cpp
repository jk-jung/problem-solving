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
    ll n, m;
    cin >> n >> m;

    ll t = m + m;
    ll cc = m % 10;
    while (t % 10 != m % 10) {
        cc += t % 10;
        ll x = t + m;
        t = x;
    }
    t -= m;
    ll cnt = n / t;
    ll r = cc * cnt;
    ll nn = t * cnt;
    while(nn <= n) {
        r += nn % 10;
        nn += m;
    }
    cout << r << endl;
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
