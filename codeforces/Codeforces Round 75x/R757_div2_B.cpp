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
    ll R = 0;
    cin >> n;
    vector<pi> v(n);
    vi r(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i].F;
        v[i].S = i + 1;
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());


    for (int i = 0, x = 1; i < n; i++) {
        R += (ll)v[i].F * ab(x) * 2ll;
        r[v[i].S] = x;
        if( x > 0) x = -x;
        else x = -x + 1;
    }
    cout << R << '\n';
    for (int x: r)cout << x << " ";
    cout << '\n';
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
