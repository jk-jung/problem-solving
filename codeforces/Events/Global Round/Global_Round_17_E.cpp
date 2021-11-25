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

    vector<pi> v;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (v.empty() || v.back().F != x) v.pb({x, 1});
        else v.back().S++;
    }

    int r = 0;
    for (int i = 0; i < v.size(); i++) {
        int t = v[i].S, nxt = i;
        for (int j = i + 1; j < v.size(); j = nxt + 1) {
            int need = (v[nxt].F - v[i].F) * 2 + v[i].F;
            nxt = lower_bound(v.begin() + j, v.end(), pi(need, 0)) - v.begin();
            if (nxt == v.size())break;
            t ++ ;
        }
        r = max(r, t);
    }

    cout << n - r << '\n';
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
