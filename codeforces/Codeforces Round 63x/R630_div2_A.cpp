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

bool can(int a, int b, int x, int x1, int x2) {
    if (a && a == b && ab(x - x1) == 0 && ab(x - x2) == 0)return false;
    if (a > b && max(1, a - b) > x - x1) return false;
    else if (a < b && max(1, b - a) > x2 - x) return false;
    return true;
}

void solve() {
    int a, b, c, d;
    int x, y, x1, y1, x2, y2;
    cin >> a >> b >> c >> d;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    cout << ((can(a, b, x, x1, x2) && can(c, d, y, y1, y2)) ? "Yes" : "No") << endl;

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
