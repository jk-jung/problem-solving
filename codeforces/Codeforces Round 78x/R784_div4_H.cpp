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
    vi v(33);
    cin >> n >> k;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        for (int j = 0; j < 31; j++)v[j] += (x >> j & 1);
    }
    int r = 0;
    for (int i = 30; i >= 0; i--) {
        int need = n - v[i];
        if(need <= k) {
            k -= need;
            r += (1 << i);
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
