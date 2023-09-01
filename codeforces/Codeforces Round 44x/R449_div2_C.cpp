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

ll d[100005];
string a = "What are you doing at the end of the world? Are you busy? Will you save us?";
string b = R"(What are you doing while sending ""? Are you busy? Will you send ""?)";

ll l(ll x) {
    if (x == 0) return a.size();
    ll &r = d[x];
    if (r) return r;
    return r = min((ll) 1e18, l(x - 1) * 2 + (ll) b.size());
}

char f(ll n, ll k) {
    if(l(n) < k)return '.';
    if (n == 0) return a[k - 1];
    ll m = l(n - 1);
    if(k <= 34) return b[k - 1];
    if(k <= m + 34) return f(n - 1, k - 34);
    if(k <= m + 66) return b[k - m - 1];
    if(k <= m * 2 + 66) return f(n - 1, k - m - 66);
    return b[k - m * 2 - 1];
}


char solve() {
    ll n, k;
    cin >> n >> k;
    return f(n, k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        cout << solve();
}
