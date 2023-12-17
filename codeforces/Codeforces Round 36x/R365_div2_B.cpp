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

void solve() {
    int n, k;
    cin >> n >> k;
    ll s = 0, r = 0;
    vi v(n);
    for (int &x: v)cin >> x, s += x;

    for (int i = 0; i < n; i++) {
        r += v[i] * v[(i + 1) % n];
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        x--;
        ll t = s;
        for(int j=-1;j<=1;j++){
            int y = (x + j + n) % n;
            t -= v[y];
        }
        r += t * v[x];
        s -= v[x];
        v[x] = 0;
    }

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
