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
    int n, b, p;
    cin >> n >> b >> p;
    int r2 = n * p;
    int r = 0;
    while (n > 1) {
        int k = 1;
        while (k * 2 <= n) k *= 2;
        r += k / 2 * (2 * b + 1);
        n -= k / 2;
    }
    cout << r << " " << r2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
