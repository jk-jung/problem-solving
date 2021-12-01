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

int n, root;
int a[200005];
int r[200005];
vi v[200005];

void solve() {
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if (i != x)v[x].pb(i);
        else root = i;
    }

    for (int i = 0; i < n; i++)cin >> a[i];
    map<int, int> ck;
    ck[root] = 0;

    for (int i = 0, cur = -1; i < n; i++) {
        int x = a[i];
        if (ck.count(x)) {
            cur++;
            int need = cur - ck[x];
            r[x] = need;
            for (int z: v[x]) ck[z] = cur;

            ck.erase(x);
        } else {
            cout << -1 << '\n';
            for (int i = 1; i <= n; i++)v[i].clear();
            return;
        }

    }
    for (int i = 1; i <= n; i++)cout << r[i] << " ";
    cout << '\n';

    for (int i = 1; i <= n; i++)v[i].clear();
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
