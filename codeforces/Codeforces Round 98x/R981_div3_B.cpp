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

int a[555][555];
int b[555][555];

void solve() {
    int n;
    cin >> n;

    int r = 0;
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> a[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i][j])continue;

            int m = a[i][j];
            for (int y = i, x = j; y < n && x < n; y++, x++) {
                m = min(m, a[y][x]);
                b[y][x] = 1;
            }
            if (m < 0)r -= m=;
        }
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
