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

set<ll> ck;

void solve() {
    ll n;
    cin >> n;
    for (ll i = 1; i * i * i < n; i++) {
        ll t = n - i * i * i;
        if (ck.count(t)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (ll i = 1; i <= 10000; i++) ck.insert(i * i * i);
    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
