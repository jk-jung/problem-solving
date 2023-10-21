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

int h[1000005];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0, x; i < m; i++) {
        cin >> x;
        h[x] = 1;
    }
    int r = 1;
    for (int i = 0, x, y; i < k; i++) {
        cin >> x >> y;
        if (!h[r]) {
            if (r == x)r = y;
            else if (r == y) r = x;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
