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
const ll mod = 1000000007;

void solve() {
    int n, m, r = 0;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &x: v)cin >> x;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (i == n - 1 && j == m - 1)continue;

            int x = j + (v[i][j] == 'R');
            int y = i + (v[i][j] == 'D');
            if (x < 0 || y < 0 || x == m || y == n)r++;
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
