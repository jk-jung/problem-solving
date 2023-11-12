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
int p[200005];
int b[200005];
int ck[200005];

void dfs(int x) {
    ck[x] = 1;
    if (!ck[p[x]])dfs(p[x]);
}

void solve() {
    cin >> n;
    int r = 0;
    for (int i = 0; i < n; i++)cin >> p[i], p[i]--;
    for (int i = 0; i < n; i++)cin >> b[i], r += b[i];

    r = r % 2 ? 0 : 1;
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (!ck[i])dfs(i), c++;
    }
    if(c >= 2)r += c;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
