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
    int n;
    string a, b;
    cin >> n >> a >> b;
    vi A(10), B(10);
    for (int i = 0; i < n; i++)A[a[i] - '0']++, B[b[i] - '0']++;

    int r1 = 0, r2 = 0;
    vi x = A, y = B;
    for (int i = 9; i >= 0; i--) {
        for (int j = i; j <= 9; j++) {
            int t = min(x[i], y[j]);
            x[i] -= t;
            y[j] -= t;
        }
        r1 += x[i];
    }
    x = A, y = B;
    for (int i = 9; i >= 0; i--) {
        for (int j = i + 1; j <= 9; j++) {
            int t = min(x[i], y[j]);
            x[i] -= t;
            y[j] -= t;
            r2 += t;
        }
    }
    cout << r1 << endl << r2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
