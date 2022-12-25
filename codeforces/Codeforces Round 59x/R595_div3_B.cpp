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

int a[200005], n;
int ck[200005], r[200005];

int go(int x, int dep = 0) {
    if (ck[x])return dep;
    ck[x] = 1;
    r[x] = go(a[x], dep + 1);
    return r[x];
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i], ck[i] = 0;
    for (int i = 1; i <= n; i++)if (!ck[i]) go(i);
    for(int i=1;i<=n;i++)cout << r[i] <<" ";
    cout << endl;
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
