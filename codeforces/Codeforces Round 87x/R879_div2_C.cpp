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

int dif(string &a, string &b) {
    int r = 0;
    for (int i = 0; i < a.size(); i++)if (a[i] != b[i]) r++;
    return r;
}

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    string c = b;
    reverse(c.begin(), c.end());

    int r = 1 << 30;
    int d1 = dif(a, b);
    int d2 = max(1, dif(a, c));

    r = min(r, d1 * 2 + (d1 % 2 == 0 ? 0 : -1));
    r = min(r, d2 * 2 + (d2 % 2 == 0 ? -1 : 0));


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
