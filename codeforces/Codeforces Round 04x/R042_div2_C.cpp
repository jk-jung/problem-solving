#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))


void solve() {
    int n;
    cin >> n;
    vi v(n);
    map<int, int> c;
    for (int &x: v) {
        cin >> x;
        int k = 0;
        while (x) {
            k += x % 10;
            x /= 10;
        }
        c[k % 3]++;
    }
    int ans = c[0] / 2 + min(c[1], c[2]);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
