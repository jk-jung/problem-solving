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

int n;
ll tot = 0;
ll a[200005];
map<ll, int> ck;

bool go(ll x) {
    if (x < 1) return false;
    if (ck.count(x)) {
        if (--ck[x] == 0)ck.erase(x);
        return true;
    }
    if (x == 1)return false;
    if (ck.begin()->F >= x)return false;

    ll y = (x + 1) / 2;
    ll z = x / 2;

    return go(y) && go(z);
}

void solve() {
    tot = 0;
    ck.clear();

    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i], tot += a[i], ck[a[i]]++;

    cout << (go(tot) ? "YES\n" : "NO\n");
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
