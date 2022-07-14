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

pi a[105][105];

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);

    for (string &s: v)cin >> s;
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)a[i][j] = mp(j, n - i - 1);

    int r = 0;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < (n + 1) / 2; j++) {
            int y = i, x = j;
            int c1 = 0, c2 = 0;
            for (int k = 0; k < 4; k++) {
                if (v[y][x] == '0') c1++;
                else c2++;
                pi tmp = a[y][x];
                y = tmp.F;
                x = tmp.S;
            }
            r += min(c1, c2);
        }
    }
    cout << r << endl;
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
