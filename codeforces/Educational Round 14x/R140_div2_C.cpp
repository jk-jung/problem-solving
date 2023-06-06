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

const int MOD = 998244353;
int a[105][105];
int d[105][105];

void add(int &x, int y) {
    x = (x + y) % MOD;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            cin >> a[i][j];
    d[0][1] = a[0][0] == 2 ? 0 : 2;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j >= 1; j--) {
            bool ok = true;
            for (int k = 0; k <= i; k++) {
                if (a[k][i] == 1 && i - k + 1 > j)ok = false;
                if (a[k][i] == 2 && i - k + 1 <= j)ok = false;
            }
            if (ok) {
                if (j == 1) {
                    for (int k = 0; k <= i; k++)
                        add(d[i][1], d[i - 1][k]);
                } else add(d[i][j], d[i - 1][j - 1]);
            }
        }
    }
    int r = 0;
    for (int i = 0; i <= n; i++)add(r, d[n - 1][i]);
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
