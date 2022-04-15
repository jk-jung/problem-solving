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
    vi s(n), e(n);
    for (int i = 0; i < n; i++)cin >> s[i] >> e[i];
    vi x = s, y = e;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int r = n;
    for (int i = 0; i < n; i++) {
        int k1 = lower_bound(y.begin(), y.end(), s[i]) - y.begin();
        int k2 = lower_bound(x.begin(), x.end(), e[i] + 1) - x.begin();

        r = min(r, k1 + n - k2);
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
