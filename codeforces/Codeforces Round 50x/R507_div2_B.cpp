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
    int t = k * 2 + 1;

    if (n <= t)cout << "1\n" << (n + 1) / 2 << endl;
    else {
        int r = 1 << 30;
        vi v;
        for (int i = k + 1; i <= t; i++) {
            int m = n - i;
            vi tt;
            if (m % t >= k + 1 || m % t == 0) {
                int rr = 1 + (m + t - 1) / t;
                if (r > rr) {
                    r = rr;
                    for (int j = 0; j < r; j++) {
                        tt.pb((k * 2 + 1) * j + i - k);
                    }
                    v = tt;
                }
            }
        }
        cout << r << endl;
        for (int x: v)cout << x << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
