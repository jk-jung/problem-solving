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

ll calc(vi &v) {
    int n = v.size(), s = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < n;) {
        int x = v[i];
        while (i < n && v[i] == x)s++, i++;
        if(s * 2 == n) return v[i] - x + 1;
    }
    return 1;
}

void solve() {
    int n;
    cin >> n;
    vi x(n), y(n);
    for (int i = 0; i < n; i++)cin >> x[i] >> y[i];

    cout << calc(x) * calc(y) << endl;
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
