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

int f(vi &v) {
    int n = v.size();
    vi bb(n + 1);
    for (int j = n - 1; j >= 0; j--)bb[j] = bb[j + 1] + (v[j] == 2);

    int r = 0;
    for (int j = 0, a = 0; j < n; j++) {
        if (v[j] == 1)a++;
        r = max(r, a + bb[j]);
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    int r = 0;
    for (int i = 0; i < n; i++) {
        vi a, b;
        for(int j=0;j<n;j++){
            if(j<i)a.pb(v[j]);
            else b.pb(v[j]);
        }
        r = max(r, f(a) + f(b));
    }

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
