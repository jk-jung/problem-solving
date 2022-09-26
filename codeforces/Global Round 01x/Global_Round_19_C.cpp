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
    vi v(n);
    for (int &x: v)cin >> x;
    ll r = 0;
    vi o, e;
    for (int i = 1; i < n - 1; i++) {
        if (v[i] % 2)o.pb(v[i]);
        else e.pb(v[i]);
    }
    sort(o.begin(), o.end());
    if (!o.empty() && (o.back() == 1 || o.size() == 1) && e.empty()) {
        cout << -1 << endl;
        return;
    }
    r = o.size();
    for (int i = 1; i < n - 1; i++)r += (v[i] / 2);
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
