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
    int n;
    cin >> n;
    int x0, y0, x1, y1;
    x0 = y0 = -100000;
    x1 = y1 = 100000;
    for (int i = 0, x2, y2, f1, f2, f3, f4; i < n; i++) {
        cin >> x2 >> y2 >> f1 >> f2 >> f3 >> f4;
        int x3 = x2, y3 = y2;
        if (f1)x2 = -100000;
        if (f3)x3 = 100000;
        if (f4)y2 = -100000;
        if (f2)y3 = 100000;
        x0 = max(x0, x2);
        x1 = min(x1, x3);
        y0 = max(y0, y2);
        y1 = min(y1, y3);
    }
    if (x0 <= x1 && y0 <= y1) {
        cout << "1 " << x0 << " " << y0 << endl;
    } else cout << "0\n";
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
