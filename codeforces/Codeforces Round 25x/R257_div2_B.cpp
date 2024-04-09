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
    ll x, y, n;
    cin >> x >> y >> n;
    // f3 = f2 - f1
    // f4 = f3 - f2 = f2 - f1 - f2 = -f1
    // f5 = f4 - f3 = -f1 - f2 + f1 = -f2
    // f6 = f5 - f4 = -f2 - (-f1) = -f2 + f1
    // f7 = f1
    // f8 = f2
    ll a[] = {x, y, y - x, -x, -y, x - y};
    cout << (a[(n - 1) % 6] % 1000000007 + 1000000007) % 1000000007 << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
