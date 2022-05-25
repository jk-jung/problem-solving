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
    vi v(n), t(2);
    for (int &x: v)cin >> x, t[x % 2]++;

    int a = t[0] % 2, b = t[1] % 2;
    bool r = true;
    if (a == 0 && b == 0) {
    } else if (a == 1 && b == 1) {
        sort(v.begin(), v.end());
        r = false;
        for (int i = 1; i < n; i++)if (v[i - 1] + 1 == v[i])r = true;
    } else {
        r = false;
    }

    cout << (r ? "YES\n" : "NO\n");
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
