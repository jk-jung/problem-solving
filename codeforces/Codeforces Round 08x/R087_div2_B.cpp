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

char a[105][105];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)cin >> (a[i] + 1);
    int r = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != 'P')continue;
            if (a[i - 1][j] == 'W')r++, a[i - 1][j] = ' ';
            if (a[i + 1][j] == 'W')r++, a[i + 1][j] = ' ';
            if (a[i][j - 1] == 'W')r++, a[i][j - 1] = ' ';
            if (a[i][j + 1] == 'W')r++, a[i][j + 1] = ' ';
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
