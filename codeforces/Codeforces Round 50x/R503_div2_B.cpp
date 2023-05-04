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

int n;
int a[1005];
int b[1005];

int dfs(int x) {
    if (b[x]) return x;
    b[x] = 1;
    return dfs(a[x]);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i], a[i]--;
    for (int i = 0; i < n; i++) {
        memset(b, 0, sizeof(b));
        cout << dfs(i) + 1 << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
