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
    int n, m;
    cin >> n >> m;
    vi t(n), s(n), e(n);
    for (int i = 0; i < n; i++)cin >> t[i] >> s[i] >> e[i];

    int L = m, R = m, last = 0;
    for (int i = 0; i < n; i++) {
        int dif = ab(last - t[i]);
        L = max(L - dif, s[i]);
        R = min(R + dif, e[i]);
        if(L > R) {
            cout <<"NO\n";
            return;
        }

        last = t[i];
    }
    cout <<"YES\n";
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
