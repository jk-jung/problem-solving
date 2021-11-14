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

int n;
int a[1000005];
int d[1000005];
int pr[1000005];
vi st[1000005];
string s;

void solve() {
    for (int i = 2; i <= 1000000; i++) {
        if (pr[i])continue;
        for (int j = i + i; j <= 1000000; j += i) pr[j] = i;
    }

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> s;
    for (int i = 0; i < n; i++)if (a[i] == 1)s[i] = '*';

    for (int i = 0; i < n; i++) {
        int x = a[i], k = 2;
        vi v;

        while(pr[x]) v.pb(pr[x]), x /= pr[x];
        if (x > 1) v.pb(x);

        d[i] = i;
        for (int y: v) {
            if (s[i] == '*') st[y].pb(i);
            else {
                if (st[y].empty()) {
                    d[i] = -1;
                    break;
                } else {
                    d[i] = min(d[i], st[y].back());
                    st[y].pop_back();
                }
            }
        }
    }

    ll r = 0;
    vector<pi> v;
    for (int i = n - 1; i >= 0; i--) {
        int cnt = 1;
        while (v.size() > 0 && v.back().F >= d[i]) {
            cnt += v.back().S;
            v.pop_back();
        }
        if (d[i] == i) r += cnt;
        v.pb({d[i], cnt});
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}