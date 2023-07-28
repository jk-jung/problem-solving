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

int t[205][205];
int n;

int f(int k) {
    int r = 0;
    for (int i = 0; i < n * 2; i++) {
        for (int j = 0; j < n * 2; j++) {
            if (t[i][j] != (((i + j) % 2) ^ k))r++;
        }
    }
    return r;
}

void solve() {
    cin >> n;
    vector<vector<string>> v(4, vector<string>(n));

    for (int i = 0; i < 4; i++) {
        for (auto &x: v[i])cin >> x;
    }
    vi a = {0, 1, 2, 3};
    int r = 1 << 30;
    do {
        for (int i = 0; i < n * 2; i++) {
            for (int j = 0; j < n * 2; j++) {
                int idx = (i >= n) * 2 + (j >= n);
                t[i][j] = v[a[idx]][i % n][j % n] - '0';
            }
        }
        r = min(r, f(0));
        r = min(r, f(1));
    } while (next_permutation(a.begin(), a.end()));
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
