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

int a[555][555];


void solve() {
    int n;
    cin >> n;
    int m = n * 2 - 1;
    for (int i = 0; i < 2 * n; i++)
        for (int j = 0; j < 2 * n; j++)cin >> a[i][j];

    ll r = 0;
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)r += a[i + n][j + n];
    int t = a[0][n];
    t = min(t, a[0][m]);
    t = min(t, a[n - 1][n]);
    t = min(t, a[n - 1][m]);
    t = min(t, a[n][0]);
    t = min(t, a[m][0]);
    t = min(t, a[n][n - 1]);
    t = min(t, a[m][n - 1]);

    cout << r + t<< endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
