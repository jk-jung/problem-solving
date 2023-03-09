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
    int x = 0, y = 0, r = 1;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == x && b == y)continue;
        int t = min(a, b);
        r += max(0, t - max(x, y) + 1);
        if(x == y) r --;
        x = a;
        y = b;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

        solve();
}
