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

int n;

int calc(int a, int b) {
    return a + n - b;
}

void solve() {
    cin >> n;
    vi c[150001];
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        c[x].pb(i);
    }

    int r = -1;
    for (auto v: c) {
        int m = v.size();
        if (m < 2)continue;

        for (int i = 0; i < m - 1; i++)
            r = max(r, calc(v[i], v[i + 1]));
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
