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


int check(int x, int y, vector<tuple<int, int, int>> &v, vi &mm) {
    int idx = lower_bound(v.begin(), v.end(), make_tuple(x, 0, 0)) - v.begin() - 1;
    if (idx == -1)return -1;
    int i = mm[idx];
    int z = get<1>(v[i]);

    return z < y ? get<2>(v[i]) + 1 : -1;
}

void solve() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> v(n);
    vi mm(n);
    vector<pi> r(n);
    int c = 0;
    for (auto &[x, y, z]: v)cin >> x >> y, z = c++;

    sort(v.begin(), v.end());
    mm[0] = 0;
    for (int i = 1; i < n; i++) {
        if (get<1>(v[i]) < get<1>(v[mm[i - 1]])) {
            mm[i] = i;
        } else {
            mm[i] = mm[i - 1];
        }
    }

    int i = 0;
    for (auto[x, y, z]: v) {
        r[i].F = z;
        r[i].S = max(check(x, y, v, mm), check(y, x, v, mm));
        i ++;
    }
    sort(r.begin(), r.end());

    for (auto[x, y]: r)cout << y << " ";
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
