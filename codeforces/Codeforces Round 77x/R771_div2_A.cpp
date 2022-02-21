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
    vi v(n);
    for (int &x: v)cin >> x;

    int target = 1;
    for (int i = 0; i < n; i++) {
        if (i + 1 == v[i]) continue;
        target = i + 1;
        break;
    }
    for (int i = 1; i < n; i++) {
        if (v[i] == target) {
            for (int s = target - 1, e = i; s < e; s++, e--) {
                swap(v[s], v[e]);
            }
        }
    }
    for (int x: v)cout << x << " ";
    cout << '\n';
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
