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
    vi v(n);
    for (int &x: v)cin >> x;

    vi cnt(32);
    for (int x: v) {
        for (int i = 0; i < 30; i++)if (x >> i & 1)cnt[i]++;
    }

    int r = -1, idx = 0;
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int k = 0; k < 30; k++)if ((v[i] >> k & 1) && cnt[k] == 1)t |= 1 << k;
        if(r < t) {
            r = t;
            idx = i;
        }
    }
    cout << v[idx];
    for (int i = 0; i < n; i++)if (i != idx)cout << " " << v[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
