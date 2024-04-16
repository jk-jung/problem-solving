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

int T[1000005];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)T[i] = T[i - 1] ^ i;

    vi v(n);
    int r = 0;
    for (int &x: v)cin >> x, r ^= x;
    for (int i = 1; i <= n; i++) {
        int q = n / i;
        int mod = n % i;
        if (q % 2 == 1) {
            r ^= T[i - 1];
        }
        r ^= T[mod];
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
