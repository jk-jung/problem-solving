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
    int n, p, k;
    cin >> n >> p >> k;
    vi v(n);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());

    int r = 0;
    for (int i = 0, s = 0; i < k; i++) {
        if (s <= p)r = max(r, i);
        for (int j = i + k - 1, s2 = 0; j < n; j += k) {
            s2 += v[j];
            if (s + s2 <= p)r = max(r, j + 1);
        }
        s += v[i];
    }
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
