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

int a[105][105];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> a[i][j];

    int r = 0, c = 0;
    for (int j = 0; j < m; j++) {
        int cost = 0, best = 0, c1 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j]) {
                int t = min(k, n - i) + i;
                int val = 0;
                for (int x = i; x < t; x++)val += a[x][j];
                if (val > best) {
                    best = val;
                    c1 = cost;
                }
                cost++;
            }
        }
        c += c1;
        r += best;
    }
    cout << r << " " << c << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
