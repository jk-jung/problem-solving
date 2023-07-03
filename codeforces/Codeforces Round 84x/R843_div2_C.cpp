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
    ll n, x;
    cin >> n >> x;

    int idx = -1;
    for (int i = 63; i >= 0; i--) {
        if ((n >> i & 1) != (x >> i & 1)) {
            idx = i;
            break;
        }
    }
    ll m = n;
    if (idx >= 0)
        m = ((n >> (idx + 1)) + 1) << (idx + 1);
    cout << ((n & m) == x ? m : -1) <<endl;

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
