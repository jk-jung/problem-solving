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
    int n, t;
    int r = 1 << 30, rr = 0;
    cin >> n >> t;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        int z = x + max(0, (t - x + y - 1) / y * y);
        if (z < r) {
            r = z;
            rr = i + 1;
        }
    }
    cout << rr << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    solve();
}
