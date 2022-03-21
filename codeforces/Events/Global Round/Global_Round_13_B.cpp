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
    int n, a, b, one = 0;
    cin >> n >> a >> b;
    vi v(n);
    for (int &x: v)cin >> x;
    for (int i = 1; i < n; i++) {
        int dif = ab(v[i - 1] - v[i]);
        if (dif >= 2) {
            cout << 0 << '\n';
            return;
        }
        else if(dif == 1)one = 1;
    }

    cout << (one == 0 ? min(b * 2, a + b) : min(a, b)) <<'\n';
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
