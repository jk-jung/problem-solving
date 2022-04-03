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

int n, k;
int a[200005];
int b[200005];

bool can(int x) {
    int cnt = 0, mm = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= x)cnt++;
        else cnt--;

        b[i] = cnt;

        if (i >= k) mm = min(mm, b[i - k]);
        if (i + 1 >= k && cnt - mm > 0) return true;
    }
    return false;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)cin >> a[i];

    int s = 1, e = n, r = 1;
    while (s <= e) {
        int m = (s + e) / 2;
        if (can(m)) r = m, s = m + 1;
        else e = m - 1;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
