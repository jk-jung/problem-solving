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
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &x: v)cin >> x;

    bool ok = false;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (v[i][j - 1] == '0' && v[i][j] == '1' && v[i][j + 1] == '0') {
                ok = true;
            }
        }
    }
    cout << (ok ? "TRIANGLE" : "SQUARE") << endl;
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
