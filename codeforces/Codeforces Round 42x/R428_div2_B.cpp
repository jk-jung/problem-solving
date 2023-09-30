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
    int n, k;
    cin >> n >> k;
    vi v(k);
    int t = 0, c = 0;
    for (int &x: v)cin >> x, t += x % 2, c += x / 2;
    int a = n * 2;
    int b = n;
    while (t--) {
        if (b > 0)b--, a++;
        else if (a > 0) a--;
        else {
            cout << "NO\n";
            return;
        }
    }
    sort(v.rbegin(), v.rend());
    for (int &x: v) {
        if (x % 2)x--;
        while (x >= 4 && b > 0) {
            x -= 4;
            c -= 2;
            b--;
        }
    }
    a += b + b / 2;
    cout << (c <= a ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
