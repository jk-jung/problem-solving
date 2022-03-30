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
    map<int, vi> ck;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ck[x].pb(i + 1);
    }

    int last = -1, i = 0;
    ll s = 0;
    for (auto&[k, v]: ck) {
        if (s < k) last = i;
        ll val = k * (ll) v.size();
        s += val;
        i++;
    }
    vi r;
    i = 0;
    for (auto&[k, v]: ck) {
        if (i >= last) for (int x: v)r.pb(x);
        i++;
    }

    sort(r.begin(), r.end());
    cout << r.size() << endl;
    for (int x: r)cout << x << " ";
    cout << endl;
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
