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
    int n, m, d;
    cin >> n >> m >> d;
    map<int, int> ck;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        ck[x] = i + 1;
    }
    vi v(m);
    for (int &x: v)cin >> x;
    int r = 1 << 30;
    for (int i = 1; i < m; i++) {
        int a = ck[v[i - 1]];
        int b = ck[v[i]];
        if (!(a < b && b <= a + d))r = 0;
        else {
            if(n - 1 > d) r = min(r, a + d + 1 - b);
            r = min(r, b - a);
        }
    }
    cout << r << endl;
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
