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
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> v(n);
    for (auto &x: v)cin >> x;

    int r = 0;
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (char x: v[i]) {
            if (x == '.') t++;
            else t = 0;
            if (t >= k)r++;
        }
    }
    if (k > 1) {
        for (int j = 0; j < m; j++) {
            int t = 0;
            for (int i = 0; i < n; i++) {
                if (v[i][j] == '.') t++;
                else t = 0;
                if (t >= k)r++;
            }
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
