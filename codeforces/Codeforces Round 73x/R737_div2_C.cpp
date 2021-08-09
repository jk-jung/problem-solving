#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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


#define MOD 1000000007
int mod = 1000000007;

ll ppow(ll x, ll y) {
    ll r = 1;
    for (x = x % mod; y; y >>= 1, x = (x * x) % mod)
        if (y & 1) r = (r * x) % mod;
    return r;
}

ll pow2[200005];
ll tmp[200005];


void solve() {
    int n, k;
    cin >> n >> k;

    if (k == 0) {
        cout << 1 << endl;
        return;
    }
    ll r = 0;
    ll d = 1;

    tmp[0] = 1;
    for (int i = 1; i <= k; i++) {
        tmp[i] = ppow(pow2[i], n);
    }
    for (int i = k; i >= 1; i--) {
        ll a11 = 1 - (n % 2 == 0 ? 1 : 0);
        ll a10 = 1 - a11;
        ll a00 = pow2[n - 1] - (n % 2 == 0 ? 1 : 0);

        ll t = a10 * tmp[i-1] % MOD * d % MOD;
        r = (r + t) % MOD;
        d = d * (a11 + a00 % MOD) % MOD;
    }
    r = (r + d) % MOD;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pow2[0] = 1;
    for (int i = 1; i <= 200000; i++)pow2[i] = (pow2[i - 1] * 2) % MOD;

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
