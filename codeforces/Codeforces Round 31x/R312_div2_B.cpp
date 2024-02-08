#include <cstring>
#include <cstdio>
#include <cmath>
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

int a[1000005];
int b[1000005];
int c[1000005];

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    memset(a, -1, sizeof(a));
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (a[v[i]] == -1) a[v[i]] = i;
        b[v[i]] = i;
        r = max(r, ++c[v[i]]);
    }
    int s = 0, e = 1 << 30;
    for (int i = 1; i <= 1000000; i++) {
        if (c[i] == r && e - s > b[i] - a[i]) {
            s = a[i];
            e = b[i];
        }
    }
    cout << s + 1 << " " << e + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
