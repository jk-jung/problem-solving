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

vi v[1000005];
ll s[1000005];

void solve() {
    int n;
    cin >> n;

    ll r = 0, c=0;
    vi vv;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        v[i].resize(m);
        for (int &x: v[i])cin >> x;
        int ok = 0;
        int m1 = v[i][0];
        int m2 = v[i][0];
        for (int x: v[i]) {
            if (x > m1)ok = 1;
            m1 = min(m1, x);
            m2 = max(m2, x);
        }
        if (ok) c++;
        else {
            vv.pb(m1);
            s[m2]++;
        }
    }
    r = c * c + c * (n - c) * 2;
    for (int i = 1000000; i >= 0; i--)s[i] += s[i + 1];
    for(int x:vv)r += s[x + 1];
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
