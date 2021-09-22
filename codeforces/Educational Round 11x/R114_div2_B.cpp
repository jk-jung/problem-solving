#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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
    int m;
    vi v(3);
    cin >> v[0] >> v[1] >> v[2] >> m;
    sort(v.begin(), v.end());

    int min_m = max(1, v[2] - v[1] - v[0]) - 1;
    int max_m = max(0, v[0] - 1) + max(0, v[1] - 1) + max(0, v[2] - 1);

    cout << (min_m <= m && m <= max_m ? "YES" : "NO") << '\n';
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
