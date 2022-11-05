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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vector<vi> s(n, vi(m, 0));
    for (auto &x: v)cin >> x;
    int r = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            s[i][j] = (v[i][j] == '*') + (j ? s[i][j - 1] : 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int y = 0; i + y < n; y++) {
                int a = j - y, b = j + y;
                int dif = b - a + 1;
                if (a >= 0 && b < m && s[i + y][b] - (a == 0 ? 0 : s[i + y][a - 1]) == dif)
                    r++;
                else break;
            }
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
