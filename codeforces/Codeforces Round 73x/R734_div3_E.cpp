#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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

const int Max = 1000000;
int mm[2005];
vector<int> v[2005];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= k; i++)mm[i] = Max;
    for (int i = 1; i <= n; i++) v[i].clear();
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (i >= x) v[x].pb(i);
    }

    mm[0] = 0;

    int r = Max;
    for (int p = 1; p <= n; p++) {
        for (int t = k; t >= 1; t--) {
            for (int q = 0; q < v[p].size(); q++) {
                int i = v[p][q];
                if (i - p < mm[t - 1])continue;
                mm[t] = min(mm[t], i - p);
                if (t == k) r = min(r, i - p);
            }
        }
    }

    cout << (r == Max ? -1 : r) << endl;
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
