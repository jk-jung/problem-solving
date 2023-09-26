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

int a[55][55];
int c[55];

void solve() {
    int n;
    cin >> n;
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            a[i][y] = 1;
            c[y] = 1;
        }
    }
    int r = 0;
    for (int k = 1; k <= 50; k++) {
        if(!c[k])continue;
        int d[55];
        memset(d, 0, sizeof(d));
        int rr = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][k])continue;
            for (int j = 1; j <= 50; j++)
                if (a[i][j] && !d[j]) {
                    d[j] = 1;
                    rr++;
                }
        }
        r = max(r, rr);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
