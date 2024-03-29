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


int go(int x, int i, int cur = 0) {
    if (x == 0) return cur;
    int r = 1 << 30;
    for (i = i + 1; i <= min(x, 9); i++) {
        r = min(r, go(x - i, i, cur * 10 + i));
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    cout << go(n, 0) << endl;
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
