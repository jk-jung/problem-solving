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
int a[1005];
int n, k;

void solve() {
    cin >> n >> k;
    int r = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (++a[x] == 2)a[x] = 0, r += 2;
    }
    int rest = (n + 1) / 2 - r / 2;
    cout << r + rest << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
