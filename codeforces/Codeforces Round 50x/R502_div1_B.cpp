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
    string a, b;
    cin >> a >> b;
    ll x = 0, y = 0, z = 0, w = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '0' && b[i] == '0')x++;
        if (a[i] == '0' && b[i] == '1')y++;
        if (a[i] == '1' && b[i] == '0')z++;
        if (a[i] == '1' && b[i] == '1')w++;
    }
    cout << x * (z + w) + y * z << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
