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


int calc(vi &v, int tar) {
    int s = 0;
    for (int x: v) {
        s += x;
        if (s == tar)s = 0;
        else if (s > tar)return false;
    }
    return true;
}

void solve() {
    int n, s = 0;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x, s += x;

    int r = n;
    for (int i = 1; i <= n; i++)
        if (s % i == 0 && calc(v, s / i))
            r = n - i;
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
