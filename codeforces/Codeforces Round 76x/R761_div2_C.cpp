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
    vi v, ck(n + 1);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (1 <= x && x <= n && ck[x] == 0) {
            ck[x] = 1;
        } else v.pb(x);
    }
    sort(v.begin(), v.end());

    int r = 0;
    for (int i = 1, pos = 0; i <= n; i++) {
        if (ck[i])continue;
        if(v[pos] % (v[pos] - i) != i) {
            r = -1;
            break;
        }
        pos ++;
        r ++;
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
