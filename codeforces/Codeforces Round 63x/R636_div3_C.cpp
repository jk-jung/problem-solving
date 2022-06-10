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
    ll r = 0;
    vi v;
    for (ll i = 0, x; i < n; i++) {
        cin >> x;
        if(v.empty() || x * v.back() > 0)v.pb(x);
        else {
            sort(v.begin(), v.end());
            r += v.back();
            v.clear();
            v.pb(x);
        }
    }
    sort(v.begin(), v.end());
    r += v.back();
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
