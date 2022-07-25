#include <string.h>
#include <stdio.h>
#include <math.h>
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

int d[1005][11];
int n, m;
int mod = 1000000007;

int go(int a, int idx) {
    if (idx == m - 1)return 1;

    int &r = d[a][idx];
    if (r != -1) return r;
    r = 0;
    for (int i = 1; i <= a; i++)r = (r + go(i, idx + 1)) % mod;
    return r;
}

void solve() {
    cin >> n >> m;
    memset(d, -1, sizeof(d));

    int r = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = n - i + 1;j >= 1; j--) {
            r = (r + (ll) go(i, 0) * go(j, 0)) % mod;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
