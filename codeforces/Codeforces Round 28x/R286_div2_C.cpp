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

int d[30005];
int st[30005][505];
int n, k;

int go(int pos, int jump) {
    if (pos > 30000) return 0;
    int &r = st[pos][jump];
    if(r!= -1)return r;
    for (int i = -1; i <= 1; i++) {
        int j = jump + i;
        int real = k + j - 250;
        if (real <= 0) continue;
        if(j < 0 || j > 500) continue;
        r = max(r, go(pos + real, j) + d[pos]);
    }
    return r;
}


void solve() {
    cin >> n >> k;
    while (n--) {
        int x;
        cin >> x;
        d[x]++;
    }
    memset(st, -1, sizeof(st));
    cout << go(k, 250) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
