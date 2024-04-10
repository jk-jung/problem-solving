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

int L[100005];
int R[100005];

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;

    L[0] = 1;
    R[n - 1] = 1;
    for (int i = 1; i < n; i++) {
        if (v[i - 1] < v[i]) L[i] = L[i - 1] + 1;
        else L[i] = 1;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (v[i] < v[i + 1]) R[i] = R[i + 1] + 1;
        else R[i] = 1;
    }
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) r = max(r, R[i + 1] + 1);
        else if (i == n - 1) r = max(r, L[i - 1] + 1);
        else if (v[i - 1] + 1 < v[i + 1]) r = max(r, L[i - 1] + R[i + 1] + 1);
        if (i > 0)r = max(r, L[i - 1] + 1);
        if (i < n - 1)r = max(r, R[i + 1] + 1);
        r = max(r, L[i]);
        r = max(r, R[i]);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
