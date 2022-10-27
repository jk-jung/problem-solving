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
    int a, b;
    string s;
    cin >> a >> b >> s;
    int n = s.size();
    vector<vi> v(n + 1, vi(2, 1 << 30));

    v[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int x = s[i - 1] - '0';
        if (x) {
            v[i][1] = min(v[i - 1][1], v[i - 1][0] + a);
        } else {
            v[i][1] = v[i - 1][1] + b;
            v[i][0] = min(v[i - 1][1], v[i - 1][0]);
        }
    }
    cout << min(v[n][0], v[n][1]) << endl;
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
