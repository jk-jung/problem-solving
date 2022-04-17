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

vi v[200005];
int cnt[200005];

int calc(int x) {
    vi &t = v[x];
    vi d(t.size());

    for (int i = 0; i < t.size(); i++) {
        d[i] = cnt[t[i]];
        for (int j = 0; j < i; j++) {
            if(t[i] % t[j] == 0)
                d[i] = max(d[i], d[j] + cnt[t[i]]);
        }
    }

    return d.back();
}

void solve() {
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }

    int r = 0;
    for (int i = 1; i <= 200000; i++)if (cnt[i])r = max(r, calc(i));
    cout << n - r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 200000; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                v[i].pb(j);
                if (j * j != i)v[i].pb(i / j);
            }
        }
        sort(v[i].begin(), v[i].end());
    }

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
