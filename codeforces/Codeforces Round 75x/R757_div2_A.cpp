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
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    vi v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end());
    int rr = 0;
    for (int x: v) {
        if (x < l)continue;
        if (x > r)continue;
        if (x <= k) {
            k -= x;
            rr++;
        }
    }
    cout << rr << endl;
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
