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
vi v[100005];
double r;

void dfs(int x, int y = -1, double dep = 0, double p = 1) {
    bool end = true;
    double c = 0;
    for (int z: v[x])if (z != y) c++;
    for (int z: v[x])
        if (z != y) {
            dfs(z, x, dep + 1, p / c);
            end = false;
        }
    if (end) r += dep * p;
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(1);
    printf("%.10lf", r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
