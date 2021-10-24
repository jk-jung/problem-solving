#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <set>
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

bool check(vi &v, int f) {
    map<int, int> ck;
    int r = 0;
    for (int x: v) r = max(r, ++ck[x % f]);
    return r >= v.size() / 2;
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++)cin >> v[i], v[i] += 1000000;
    if (check(v, 1000000000)) {
        cout << -1 << endl;
        return;
    }

    int r = 1;
    set<int> vv;
    for (int i = 0; i < n; i++)for (int j = i + 1; j < n; j++)vv.insert(ab(v[i] - v[j]));
    for (int dif: vv) {
        if(!dif)continue;
        if(check(v, dif)) { r = max(r, dif); continue;}
        int m = sqrt(dif) + 1;
        for (int k = 2; k <= m; k++){
            if (dif % k) continue;
            int k2 = dif / k;
            if (check(v, k)) r = max(r, k);
            if (check(v, k2)) r = max(r, k2);
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
