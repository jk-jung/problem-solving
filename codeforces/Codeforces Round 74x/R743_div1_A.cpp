#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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


vi v[200005];
int no;
int ck[200005], CK;
int d[200005];

int go(int x) {
    if (ck[x] == CK) {
        no = 1;
        return 0;
    }
    if (d[x] != -1)return d[x];
    ck[x] = CK;
    d[x] = 1;

    for (int y: v[x]) {
        d[x] = max(d[x], go(y) + (x < y ? 1 : 0));
    }
    ck[x] = 0;
    return d[x];
}

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int k, x;
        cin >> k;

        for (int j = 0; j < k; j++) {
            cin >> x;
            v[i].pb(x);
        }

        d[i] = -1;
    }

    int r = -1;
    no = 0;
    for (int i = 1; i <= n; i++) {
        CK++;
        r = max(r, go(i));
        if (no == 1) {
            r = -1;
            break;
        }
    }
    cout << r << '\n';

    for (int i = 1; i <= n; i++) {
        v[i].clear();
        d[i] = -1;
    }
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
