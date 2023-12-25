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
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    ll r = 0;
    for (int i = 1; i <= n; i++) {
        int x = i + b - c;
        int y = i + a - d;
        int z = i + a + b - c - d;
        if (x >= 1 && x <= n && y >= 1 && y <= n && z >= 1 && z <= n) r++;
    }
    cout << r * n << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
