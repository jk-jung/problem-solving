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
    int n, idx = 0;
    cin >> n;
    vector<pi> v(n);

    for (auto &[x, i]: v) cin >> x, i = idx++;
    sort(v.begin(), v.end());
    string r;
    for (int i = 0, s = n + 1, e = -1; i < n; i++) {
        s = min(s, v[i].S);
        e = max(e, v[i].S);
        if (e - s == i)r += '1';
        else r += '0';
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
