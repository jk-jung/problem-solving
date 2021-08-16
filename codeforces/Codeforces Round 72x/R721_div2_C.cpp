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

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];


    ll r = 0;
    map<int, vi> ck;
    for (int i = 0; i < n; i++) ck[v[i]].pb(i);
    for (auto it : ck) {
        vi &t = it.S;
        ll s = 0;
        for (ll i = 0; i < t.size(); i++) {
            r += s * (n - t[i]);
            s += (t[i] + 1);
        }
    }
    cout << r << endl;
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
