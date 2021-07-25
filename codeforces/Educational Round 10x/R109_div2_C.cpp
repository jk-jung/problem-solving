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

int a[300005];
int r[300005];
char s[300005];
int n, m;

void calc(vector<int> &v) {
    vector<int> L, R;
    for (int i = 0; i < v.size(); i++) {
        int k = v[i];
        if (s[k] == 'R')R.pb(k);
        else {
            if (!R.empty()) {
                r[R.back()] = r[k] = (a[k] - a[R.back()]) / 2;
                R.pop_back();
            } else L.pb(k);
        }
    }
    for (int i = 0; i + 1 < L.size(); i += 2)
        r[L[i]] = r[L[i + 1]] = (a[L[i + 1]] + a[L[i]]) / 2;
    for (int i = int(R.size()) - 1; i - 1 >= 0; i -= 2)
        r[R[i]] = r[R[i - 1]] = (m + m - a[R[i]] - a[R[i - 1]]) / 2;
    if (L.size() & 1 && R.size() & 1)
        r[R[0]] = r[L.back()] = (m + m - a[R[0]] + a[L.back()]) / 2;
}

void solve() {
    cin >> n >> m;
    vector<pi> v;
    for (int i = 0; i < n; i++)cin >> a[i], r[i] = -1, v.pb({a[i], i});
    for (int i = 0; i < n; i++)cin >> s[i];
    sort(v.begin(), v.end());


    vector<int> v1, v2;
    for (int i = 0; i < n; i++) {
        if (v[i].F & 1) v1.pb(v[i].S);
        else v2.pb(v[i].S);
    }
    calc(v1);
    calc(v2);

    for (int i = 0; i < n; i++)cout << r[i] << " ";
    cout << endl;
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
