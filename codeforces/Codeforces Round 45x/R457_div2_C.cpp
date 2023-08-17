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
    int n, m;
    cin >> n >> m;

    cout << "100003 100003\n";
    for (int i = 1; i < n; i++) {
        cout << i << " " << i + 1 << " " << (i == 1 ? 100003 - n + 2 : 1) << "\n";
        m--;
    }
    int x = 1, y = 2;
    while (m--) {
        y++;
        if (y > n) {
            x++;
            y = x + 2;
        }
        cout << x << " " << y << " " << 1000000000 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
