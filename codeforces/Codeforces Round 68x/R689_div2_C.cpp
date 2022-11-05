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
    int n, m;
    cin >> n >> m;
    vi v(n);
    for (int &x: v)cin >> x;
    int c = n;
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] != i + 1) break;
        c--;
    }
    double r = 1;
    while (m--) {
        int x;
        double y;
        cin >> x >> y;

        if (x >= c)r *= (1 - y);
    }
    if (c == 0)r = 0;
    printf("%.10lf\n", 1 - r);
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
