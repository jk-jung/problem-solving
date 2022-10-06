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
    int n, k, z;
    cin >> n >> k >> z;
    vi v(n);
    for (int &x: v)cin >> x;

    int r = 0;
    for (int i = 0; i <= z; i++) {
        if (i * 2 > k)continue;
        int t = 0, s = 0;
        for (int j = 0; j <= k - i * 2; j++) {
            t = max(t, v[j] + v[j + 1]);
            s += v[j];
        }
        r = max(r, s + i * t);
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
