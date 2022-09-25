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
int d[255][255];
int ck[255];

int dfs(int x) {
    ck[x] = 1;
    int r = 1;
    for (int i = 0; i < 255; i++)if (d[x][i] && !ck[i])r += dfs(i);
    return r;
}

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    memset(ck, 0, sizeof(ck));

    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            cout << "-1\n";
            return;
        }
        if (a[i] != b[i]) {
            d[a[i]][b[i]] = 1;
            d[b[i]][a[i]] = 1;
        }
    }
    int r= 0;
    for (int i = 0; i < 255; i++)r += dfs(i) - 1;

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
