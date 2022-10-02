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
    vi v(n), c(2);
    for (int &x: v)cin >> x, c[x]++;
    if (c[0] < c[1]) {
        int m = c[1] - c[1] % 2;
        cout << m << endl;
        for (int i = 0; i < m; i++)cout << 1 << " ";
        cout << endl;
    } else {
        cout << c[0] << endl;
        for (int i = 0; i < c[0]; i++)cout << 0 << " ";
        cout << endl;
    }
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
