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

int r[15][15];

void solve() {
    int n, t;
    cin >> n >> t;

    for (int i = 1; i <= t; i++) {
        r[1][1] += 1024;
        for (int k = 1; k <= n; k++) {
            for (int p = 1; p <= k; p++) {
                if (r[k][p] >= 1024) {
                    int x = r[k][p] - 1024;
                    r[k][p] = 1024;
                    r[k + 1][p] += x / 2;
                    r[k + 1][p + 1] += x / 2;
                }
            }
        }
    }
    int a = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (r[i][j] == 1024)a++;
        }
    }
    cout << a << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
