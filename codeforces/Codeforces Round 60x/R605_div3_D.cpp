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
    int n;
    cin >> n;
    vi v(n), d(n, 1), d2(n, 1);
    for (int &x: v)cin >> x;

    int r = 1;
    for (int i = 1; i < n; i++) {
        if (v[i - 1] < v[i]) d[i] = max(d[i], d[i - 1] + 1);
        if (v[i - 1] < v[i]) d2[i] = max(d2[i], d2[i - 1] + 1);
        if (i >= 2 && v[i - 2] < v[i]) d2[i] = max(d2[i], d[i - 2] + 1);
        r = max(r, d[i]);
        r = max(r, d2[i]);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
