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
    vi v(n / 2);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());

    int a = 0, b = 0;
    for (int i = 1; i <= n; i += 2) {
        int j = i + 1;
        a += ab(v[i/2] - i);
        b += ab(v[i/2] - j);
    }
    cout << min(a, b) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
