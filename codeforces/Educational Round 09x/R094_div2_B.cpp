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


int calc(int i, int a, int b, int x_cnt, int y_cnt, int x, int y) {
    if ((ll)i * y > a) return 0;
    int r = i;
    a -= i * y;
    int rax = min(a / x, x_cnt);
    r += rax;
    x_cnt -= rax;

    int rbx = min(b / x, x_cnt);
    r += rbx;
    b -= rbx * x;

    return r + min(b / y, y_cnt - i);
}

void solve() {
    int a, b;
    int x_cnt, y_cnt;
    int x, y;
    cin >> a >> b >> x_cnt >> y_cnt >> x >> y;

    if (x > y) {
        swap(x, y);
        swap(x_cnt, y_cnt);
    }

    int r = 0;
    for (int i = 0; i <= y_cnt; i++) {
        r = max(r, calc(i, a, b, x_cnt, y_cnt, x, y));
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
