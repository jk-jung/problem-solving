#include <cstring>
#include <cstdio>
#include <cmath>
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
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int r0 = c - e <= 1;
    int r1 = d - e <= 1;
    int r2 = c + e >= a;
    int r3 = d + e >= b;
    if ((r0 && r1) || (r2 && r3) || (r0 && r2) || (r1 && r3)) {
        cout << -1 << endl;
    } else cout << a + b - 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
