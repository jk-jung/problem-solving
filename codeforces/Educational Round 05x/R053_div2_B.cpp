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
    cin >> n;
    vi a(n), b(n), used(n + 1);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;
    int i = 0;
    for (int x: b) {
        if (used[x]) {
            cout << 0 << ' ';
            continue;
        };
        int r = 1;
        while (a[i] != x) used[a[i++]] = 1, r++;
        i ++;
        cout << r << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
