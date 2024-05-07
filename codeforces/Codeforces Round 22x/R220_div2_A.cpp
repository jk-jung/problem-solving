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

int n, m, i, j, a, b;

int distance(int y, int x) {
    int dy = ab(y - i);
    int dx = ab(x - j);
    if (dy % a != 0 || dx % b != 0) return 1e9;
    y = dy / a;
    x = dx / b;
    if (y % 2 != x % 2) return 1e9;
    if(x == 0 && y == 0)return 0;
    if(i - a < 1 && i + a > n || j - b < 1 && j + b > m)return 1e9;
    return max(dy / a, dx / b);
}

void solve() {
    cin >> n >> m >> i >> j >> a >> b;
    int r = distance(1, 1);
    r = min(r, distance(1, m));
    r = min(r, distance(n, m));
    r = min(r, distance(n, 1));
    if(r > 1e8) cout << "Poor Inna and pony!" << endl;
    else cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
