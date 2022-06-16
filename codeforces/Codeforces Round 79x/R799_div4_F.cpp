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
    int n;
    cin >> n;
    vi v(n), t, cnt(10);
    for (int &x: v)cin >> x, x %= 10;
    for (int x: v)if (cnt[x] < 3) t.pb(x), cnt[x]++;

    int m = t.size();
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            for (int k = j + 1; k < m; k++) {
                if ((t[i] + t[j] + t[k]) % 10 == 3) {
                    cout << "YES\n";
                    return;
                }
            }
    cout << "NO\n";
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
