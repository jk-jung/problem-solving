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

int v[100005];
int d[2][100005];

void solve() {
    int n, max_k = 1;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> v[i];
    while (max_k * (max_k + 1) / 2 <= n) max_k++;

    d[0][n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
        d[0][i] = max(v[i], d[0][i + 1]);

    int need = 1, r = 1, x=0, y=1;
    for (int k = 2; k < max_k; k++) {
        ll s = 0;
        for (int i = n - 1; i >= 0; i--) {
            d[y][i] = 0;

            s += v[i];
            if (i + k < n) s -= v[i + k];

            if (i + k + need <= n) {
                int t = d[x][i + k];
                if (t != (1 << 30) && s < t) {
                    r = k;
                    d[y][i] = s;
                }
                d[y][i] = max(d[y][i], d[y][i + 1]);
            }
        }
        need += k;
        swap(x, y);
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
