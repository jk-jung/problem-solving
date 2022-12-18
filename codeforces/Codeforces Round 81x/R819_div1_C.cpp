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
string s;
int pos[200005];

int dfs(int a, int b) {
    if (a >= b)return 0;
    int r = 1;
    for (int i = a; i < b; i = pos[i] + 1) {
        r += dfs(i + 1, pos[i]);
    }
    return r;
}

void solve() {
    cin >> n >> s;
    n *= 2;
    vi v;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')v.pb(i);
        else pos[v.back()] = i, v.pop_back();
    }
    cout << dfs(0, n) << endl;
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
