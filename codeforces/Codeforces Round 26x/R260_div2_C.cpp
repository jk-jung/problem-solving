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

ll a[100005];
ll d[100005][2];

void solve() {
    int n;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a[x]++;
    }
    d[1][1] = a[1];
    for (int i = 2; i <= 100000; i++) {
        d[i][0] = max(d[i - 1][0], d[i - 1][1]);
        d[i][1] = d[i - 1][0] + a[i] * i;
    }
    cout << max(d[100000][0], d[100000][1]);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
