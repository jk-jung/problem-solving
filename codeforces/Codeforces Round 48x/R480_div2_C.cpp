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
    vi v(n), c(256, -1), d(256, 0);
    for (int &x: v)cin >> x;

    for (int x: v) {
        if (c[x] == -1) {
            int t = x;
            int last = -1;
            for (int i = x; i > x - k && i >= 0; i--) {
                if (c[i] != -1) {
                    last = c[i];
                    break;
                }
                t = i;
            }
            if (last != -1 && x - t + 1 <= d[last]) {
                t = last;
            } else {
                d[t] = k;
            }
            for (int i = t; i <= x; i++){
                if(c[i] == -1) c[i] = t, d[t]--;
            }
        }
        cout << c[x] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
