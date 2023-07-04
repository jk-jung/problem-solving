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
int w, d, h, a, b, x, y;

int f(int p, int q) {
    return ab(p - x) + ab(q - y);
}

void solve() {
    cin >> w >> d >> h >> a >> b >> x >> y;


    int r = 1 << 30;
    r = min(r, a + f(0, b));
    r = min(r, w - a + f(w, b));
    r = min(r, b + f(a, 0));
    r = min(r, d - b + f(a, d));

    cout << r + h << endl;
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
