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

void solve() {
    int n, one = 0;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++)cin >> v[i], one += v[i];

    if (one % 2 == 1 || one == n) {
        cout << "NO\n";
        return;
    }

    vector<pi> t;
    for (int i = 0, cnt = 0; i < n; i++) {
        if (v[i] == 1)cnt++;
        else cnt = 0;
        if (i == n - 1 || v[i + 1] == 0) {
            if (cnt > 0)
                t.pb({i - cnt + 1, i});
        }
    }
    vi r;
    int ck = 0;
    for (int i = 0; i < t.size(); i++) {
        if (ck) {
            ck = 0;
            for (int j = t[i - 1].S; j < t[i].F - 1; j += 2)r.pb(j);

            int dis = t[i].F - t[i - 1].S - 1;
            if (dis % 2) {
                for (int j = t[i].F - 2; j >= t[i - 1].F; j -= 2)r.pb(j);
                t[i].F++;
            } else {
                t[i].F = t[i - 1].F;
            }

        }
        if ((t[i].S - t[i].F + 1) % 2) {
            ck = 1;
        } else {
            auto[s, e] = t[i];
            if (e != n-1) for (int j = e - 1; j >= s; j -= 2) r.pb(j);
            else if(s != 0) for (int j = s - 1; j < e; j += 2) r.pb(j);
            else {
                cout << "NO\n";
                return;
            }
        }
    }
    if (ck) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << r.size() << '\n';
    for (int x: r)cout << x + 1 << " ";
    cout << '\n';
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
