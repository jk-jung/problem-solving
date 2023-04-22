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

const int M = 15000000;
int p[M + 1];
int cnt[M + 1];

void solve() {
    int n, g = 0;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x, g = gcd(x, g);
    for (int &x: v)x /= g;

    for (int x: v)cnt[x]++;
    if (cnt[1] == n) {
        cout << "-1\n";
        return;
    }

    int r = n;
    for (int i = 2; i <= M; i++) {
        if (p[i])continue;
        int t = 0;
        for (int j = i; j <= M; j += i) {
            p[j] = 1;
            t += cnt[j];
        }
        r = min(r, n - t);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
