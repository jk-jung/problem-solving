#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int a, x, y;
    cin >> a >> x >> y;
    a *= 2;
    x *= 2;
    y *= 2;
    int b = a / 2;

    if (y % a == 0) {
        cout << -1;
        return;
    }
    int h = y / a;
    int t = (h + 1) / 2;
    if (h == 0) {
        cout << (-b < x && x < b ? 1 : -1);
    } else if (h % 2 == 1) {
        cout << (-b < x && x < b ? t * 3 - 1 : -1);
    } else {
        if (-a < x && x < 0) cout << t * 3;
        else if (0 < x && x < a) cout << t * 3 + 1;
        else cout << -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
