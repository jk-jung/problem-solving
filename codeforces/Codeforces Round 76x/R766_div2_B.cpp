#include <string.h>
#include <stdio.h>
#include <math.h>
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
    int n, m;
    cin >> n >> m;
    vi v;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            v.pb(max(max(i + j, n - i - 1 + j), max(n - i - 1 + m - j - 1, i + m - j - 1)));
        }
    sort(v.begin(), v.end());
    for (int i = 0; i < n * m; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
