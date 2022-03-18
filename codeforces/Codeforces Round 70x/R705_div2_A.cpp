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
    int n, k;
    cin >> n >> k;
    vi v(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i == k)v[k] = 1;
        if (i != k - i && k - i >= 1)v[min(i, k-i)] = 1;
    }
    int r = 0;
    for (int i = 1; i <= n; i++)if (!v[i])r++;
    cout << r << endl;
    for (int i = 1; i <= n; i++)if (!v[i]) cout << i << " ";
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
