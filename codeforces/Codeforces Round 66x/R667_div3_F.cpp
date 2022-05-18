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

int n, k;
string a, b;
int d[205][205][205];

int go(int idx, int use, int already) {
    if (use > k) return -(1 << 30);
    if (idx == n) return 0;

    int &r = d[idx][use][already];
    if (r != -1) return r;
    char x = a[idx];
    r = go(idx + 1, use, already + (x == b[0])) + (x == b[1] ? already : 0);

    for (char y = 'a'; y <= 'z'; y++) {
        r = max(r, go(idx + 1, use + 1, already + (y == b[0])) + (y == b[1] ? already : 0));
    }
    return r;
}

void solve() {
    memset(d, -1, sizeof(d));

    cin >> n >> k >> a >> b;
    cout << go(0, 0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
