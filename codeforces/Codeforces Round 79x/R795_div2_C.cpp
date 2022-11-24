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
    int n, k;
    string s;
    cin >> n >> k >> s;
    int m = n + 1, M = -1, c = 0;
    for (int i = 0; i < n; i++)if (s[i] == '1')M = i, m = min(m, i), c++;
    M = n - M - 1;
    int r = c * 11;
    if (c == 0);
    else if (c == 1) {
        if (M <= k) r -= 10;
        else if(m <= k) r -= 1;
    } else {
        if (M <= k) {
            r -= 10;
            k -= M;
        }
        if(m <= k) r -= 1;
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
