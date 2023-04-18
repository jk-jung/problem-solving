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
    int n, k;
    cin >> n >> k;
    vi v(n);
    for (int &x: v)cin >> x;
    sort(v.rbegin(), v.rend());

    int r = 0, cur = 0;
    for (int h = v[0], i = 0; h >= 0; h--) {
        while (i < n && v[i] == h)i++;
        if (i == n)break;
        if (cur + i > k)cur = i, r++;
        else cur += i;
    }
    cout << r + (cur ? 1 : 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
