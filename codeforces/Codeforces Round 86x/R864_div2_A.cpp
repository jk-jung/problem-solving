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
int n, m;

int ck(int y, int x) {
    if (y == 1 && x == 1) return 2;
    if (y == 1 && x == m) return 2;
    if (y == n && x == m) return 2;
    if (y == n && x == 1) return 2;
    if (y == 1 || y == n || x == 1 || x == m)return 3;
    return 4;
}

void solve() {
    int y1, x1, y2, x2;
    cin >> n >> m >> y1 >> x1 >> y2 >> x2;
    cout << min(ck(y1, x1), ck(y2, x2)) << endl;
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
