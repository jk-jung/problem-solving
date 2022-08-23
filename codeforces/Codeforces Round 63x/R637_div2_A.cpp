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
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    int x1 = n * (a - b);
    int x2 = n * (a + b);
    int y1 = c - d;
    int y2 = c + d;
    int x = max(x1, y1);
    int y = min(x2, y2);
    cout << (y - x>=0 ? "Yes" : "No") << endl;
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
