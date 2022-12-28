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

int d[200005][2];

void solve() {
    int n;
    cin >> n;
    string s;
    vi v(n);
    cin >> s;
    for (int &x: v)cin >> x;
    if (s[0] == '1') d[0][1] = v[0], d[0][0] = -1;
    else d[0][1] = -1, d[0][0] = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == '1') {
            if (d[i - 1][0] != -1) d[i][0] = d[i - 1][0] + v[i - 1];
            else d[i][0] = -1;
            d[i][1] = max(d[i - 1][0], d[i - 1][1]) + v[i];
        } else {
            d[i][0] = max(d[i - 1][0], d[i - 1][1]);
            d[i][1] = -1;
        }
    }
    cout << max(d[n - 1][0], d[n - 1][1]) << endl;
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
