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

int n;

int f(int a, int b) {
    if (a == 0 || a == n || b == 0 || b == n) return abs(a - b);
    return min(a + b, 2 * n - a - b);
}

void solve() {
    int x0, y0, x1, y1;
    cin >> n >> x0 >> y0 >> x1 >> y1;
    if(x0 == x1 && (x0 == 0 || x0 == n)) {
        cout << abs(y0 - y1) << endl;
        return;
    }else if(y0 == y1 && (y0 == 0 || y0 == n)) {
        cout << abs(x0 - x1) << endl;
        return;
    }
    cout << f(x0, x1) + f(y0, y1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
