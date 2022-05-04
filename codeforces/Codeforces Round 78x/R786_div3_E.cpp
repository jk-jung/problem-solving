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


int calc2(int x, int y) {
    int s = 1, e = max(x, y), r = -1;
    while (s <= e) {
        int m = (s + e) / 2;
        int t = max(0, x - m) + max(0, y - m);
        if (t <= m)r = m, e = m - 1;
        else s = m + 1;
    }
    return r;
}


int calc3(int x, int y) {
    int r = 1 << 30;
    for(int i=0;i<10;i++){
        int a = max(0, x - i);
        int b = max(0, y - i);
        r = min(r, (a + 1) / 2 + (b + 1) / 2 + i);
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    int r = 1 << 30;
    for (int &x: v)cin >> x;

    for (int i = 1; i < n; i++) {
        r = min(r, calc2(v[i - 1], v[i]));
    }
    for (int i = 2; i < n; i++) {
        r = min(r, calc3(v[i - 2], v[i]));
    }


    sort(v.begin(), v.end());
    r = min(r, (v[0] + 1) / 2 + (v[1] + 1) / 2);
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
