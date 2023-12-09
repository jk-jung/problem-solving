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

int a[100005];
int b[100005];
void solve() {
    ll n, m, k;
    cin >> n >> k;
    m = n;

    while (k--) {
        int y, x;
        cin >> y >> x;

        if(!a[y])n--, a[y] = 1;
        if(!b[x])m--, b[x] = 1;
        cout << n * m << " ";

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
