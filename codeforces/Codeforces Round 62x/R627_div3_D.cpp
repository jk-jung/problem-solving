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

    vi a(n), b(n), v(n);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;
    for (int i = 0; i < n; i++)v[i] = a[i] - b[i];
    sort(v.begin(), v.end());

    ll r = 0;
    for (int i = 0, j = n - 1; i < n; i++) {
        while (j >= 0 && v[i] + v[j] > 0) j--;
        r += n - j - 1;
        if (v[i] > 0) r--;
    }
    cout << r / 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
