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
    int n, x, y;
    cin >> n >> x >> y;
    int m = n / 2;
    if (x == m && y == m)cout << "NO";
    else if (x == m && y == m + 1) cout << "NO";
    else if (x == m + 1 && y == m) cout << "NO";
    else if (x == m + 1 && y == m + 1) cout << "NO";
    else cout << "YES";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
