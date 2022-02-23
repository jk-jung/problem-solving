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

int X[200005];
int Y[200005];
int Xc[200005], CK;
int Yc[200005];

void solve() {
    CK ++;
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<pi> v(q);
    int xx = 0, yy = 0;

    for (auto &x: v)cin >> x.F >> x.S;

    int cnt = 0;
    for (int i = q - 1; i >= 0; i--) {
        int y = v[i].F;
        int x = v[i].S;

        if(Xc[x] != CK) X[x] = 0;
        if(Yc[y] != CK) Y[y] = 0;
        Xc[x] = CK;
        Yc[y] = CK;


        if (Y[y] && X[x]) continue;
        if (xx == m || yy == n)break;

        if (X[x]++ == 0) xx++;
        if (Y[y]++ == 0) yy++;
        cnt++;
    }

    ll r = 1;
    for (int i = 0; i < cnt; i++)r = (r * k) % 998244353;
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
