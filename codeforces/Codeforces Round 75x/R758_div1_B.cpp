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
    int n, a, b;
    cin >> n >> a >> b;
    vi r(n), v(n);


    if (a >= b)
        for (int i = 1; i <= n; i++)v[i - 1] = i;
    else for (int i = 1; i <= n; i++)v[i - 1] = n - i + 1;

    if (a == 0 && b == 0) {
        for (int x: v)cout << x << " ";
        cout << '\n';
        return;
    }
    if (ab(a - b) >= 2 || a + b > n - 2) {
        cout << "-1\n";
        return;
    }

    r[0] = v[0];
    r[n - 1] = v.back();
    for (int i = 1; i + 1 < n; i += 2) {
        if (a > 0 && b > 0) {
            r[i] = v[i + 1];
            r[i + 1] = v[i];
            a--, b--;
        } else {
            r[i] = v[i];
            r[i + 1] = v[i + 1];
        }
    }
    if(a || b)swap(r[n-1], r[n-2]);

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
