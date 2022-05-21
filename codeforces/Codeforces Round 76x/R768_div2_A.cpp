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


int mx(vi &v) {
    int r = v[0];
    for (int x: v)r = max(r, x);
    return r;
}

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n), v(n), v2(n);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;
    for (int i = 0; i < n; i++)v[i] = max(a[i], b[i]);
    for (int i = 0; i < n; i++)v2[i] = min(a[i], b[i]);
    cout << mx(v) * mx(v2) << endl;
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
