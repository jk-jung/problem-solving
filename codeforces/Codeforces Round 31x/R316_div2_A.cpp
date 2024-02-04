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
    int n, m;
    cin >> n >> m;
    vi r(n + 1);
    int mm = 0;
    for (int i = 0; i < m; i++) {
        int idx = -1, c = -1;
        for (int j = 0, x; j < n; j++) {
            cin >> x;
            if (x > c) {
                c = x;
                idx = j + 1;
            }
        }
        mm = max(mm, ++r[idx]);
    }
    for (int i = 1; i <= n; i++)
        if (r[i] == mm) {
            cout << i << " ";
            return;
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
