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


void process(vi &v) {
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++)v[i] += v[i - 1];
}

int check(vi &a, vi &b, int k) {
    if (k <= 0)return 0;
    if (a.size() < k || b.size() < k)return -1;
    return a[k - 1] + b[k - 1];
}

void solve() {
    int n, k;
    cin >> n >> k;
    vi a, b, c;
    for (int i = 0, x, y, z; i < n; i++) {
        cin >> x >> y >> z;
        if (y && z)c.pb(x);
        else if (y) a.pb(x);
        else if (z) b.pb(x);
    }
    process(a);
    process(b);
    process(c);

    int r = check(a, b, k);
    for (int i = 0; i < c.size(); i++) {
        int tmp = check(a, b, k - i - 1);
        if(tmp >= 0) {
            tmp += c[i];
            r = r == -1 ? tmp : min(r, tmp);
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
