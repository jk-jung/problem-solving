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

int d[1005][1005][2];
int N;
int mod = 1000000007;

int go(int n, int k, int di) {
    if (k == 1) return 1;
    if(!(1 <= n && n <= N)) return 1;

    int &r = d[n][k][di];
    if (r != -1) return r;

    r = 1;
    r = (r + go(n + (di == 0 ? 1 : -1), k - 1, di ^ 1)) % mod;
    r = r + go(n + (di == 0 ? -1 : 1), k, di) - 1;
    if (r < 0) r += mod;
    if (r >= mod)r -= mod;
    return r;
}

void solve() {
    int n, k;
    cin >> n >> k;
    N = n;
    memset(d, -1, sizeof(d));
    cout << go(n, k, 0) << endl;

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
