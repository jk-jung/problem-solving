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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];

    if (v[0][0] == '1') {
        cout << -1 << endl;
        return;
    }
    int r = 0;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)if (v[i][j] == '1') r++;
    cout << r << endl;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (v[i][j] == '1') {
                if (i == 0) {
                    cout << i + 1 << " " << j << " " << i + 1 << " " << j + 1 << '\n';
                } else {
                    cout << i << " " << j + 1 << " " << i + 1 << " " << j + 1 << '\n';
                }
            }
        }
    }
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
