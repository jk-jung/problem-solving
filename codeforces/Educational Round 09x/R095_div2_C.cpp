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
    vi v(n);
    for (int &x: v)cin >> x;
    if(n == 1) {
        cout << v[0] << endl;
        return;
    }
    vector<vi> d(n, vi(2, 1 << 30));
    d[0][1] = v[0];
    d[1][1] = v[0] + v[1];

    for (int i = 1; i < n; i++) {
        for (int k = 0; k < 2; k++) {
            for (int len = 0; len < 2; len++) {
                if (i - len - 1 < 0)continue;
                int one = 0;
                for (int j = i - len; j <= i; j++)one += v[j];
                if (k == 0)one = 0;
                d[i][k] = min(d[i][k], d[i - len - 1][k ^ 1] + one);
            }
        }
    }
    cout << min(d[n - 1][0], d[n - 1][1]) << endl;
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
