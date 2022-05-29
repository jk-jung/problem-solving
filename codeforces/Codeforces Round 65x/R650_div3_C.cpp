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
    int n, k;
    string s;
    cin >> n >> k >> s;
    vi pos(n);
    for (int i = n - 1, last = 1 << 30; i >= 0; i--) {
        pos[i] = last;
        if (s[i] == '1')
            last = i;
    }

    int r = 0, x = -(1 << 30);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            x = i;
        } else if (x < i - k && i + k < pos[i]) {
            x = i;
            r++;
        }
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
