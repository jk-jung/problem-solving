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
    vi v(n), last(n + 1, -1), cnt(n + 1);
    for (int &x: v)cin >> x;
    int r = n;

    for (int i = 0; i < n; i++) {
        int x = v[i];
        if (last[x] + 1 != i)cnt[x]++;
        last[x] = i;
    }
    for (int i = 1; i <= n; i++)if (v.back() != i)cnt[i]++;
    for (int x: v) r = min(r, cnt[x]);
    cout << r << endl;
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
