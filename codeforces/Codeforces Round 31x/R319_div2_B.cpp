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
    vi v(n), d(m + 1);
    d[0] = 1;
    for (int &x: v)cin >> x;
    for (int x: v) {
        vi d2(m + 1);
        x %= m;
        for (int i = 0; i <= m; i++) {
            if (d[i]) {
                if((i + x) % m == 0) {
                    cout << "YES";
                    return;
                }
                d2[(i + x) % m] = 1;
            }
        }
        for (int i = 0; i <= m; i++)d2[i] |= d[i];
        d = d2;
    }
    cout << "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
