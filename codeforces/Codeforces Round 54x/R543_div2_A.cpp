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
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> ck;
    vi a(n), b(n);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;
    for (int i = 0; i < n; i++) {
        ck[b[i]] = max(ck[b[i]], a[i]);
    }
    int r = 0;
    for (int i = 0; i < k; i++) {
        int x = 0;
        cin >> x;
        x--;
        if (a[x] != ck[b[x]])r++;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
