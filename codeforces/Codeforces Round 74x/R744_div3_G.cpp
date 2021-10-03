#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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

int d[10005][2005];
int v[10005];
int Max = 1 << 30;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> v[i];
    for (int i = 0; i < n; i++)for (int j = 0; j < 2000; j++)d[i][j] = Max;
    d[0][0] = v[0];

    for (int i = 1; i < n; i++) {
        for (int k = 0; k < 2000; k++) {
            int len = d[i - 1][k];
            if (len == Max)continue;

            for (int op = -1; op <= 1; op++) {
                if (!op)continue;
                int x = v[i] * op;
                int pos = k + x;

                if (pos <= 0) d[i][0] = min(d[i][0], len - pos);
                else if (pos >= len) d[i][0] = min(d[i][0], pos);
                else {
                    int t = min(pos, len - pos);
                    d[i][t] = min(d[i][t], len);
                }
            }
        }
    }
    int r = Max;
    for (int i = 0; i < 2000; i++)r = min(r, d[n - 1][i]);
    cout << r << '\n';
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
