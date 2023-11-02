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
    int n, k, t;
    cin >> n >> k >> t;
    vi a(1024);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a[x]++;
    }
    while (k--) {
        vi b(1024);
        for (int i = 0, st = 0; i < 1024; i++) {
            if (a[i] == 0)continue;
            int x = a[i] / 2, y = (a[i] + 1) / 2;
            if (!st)swap(x, y);
            b[i ^ t] += x;
            b[i] += y;
            st = (st + a[i]) % 2;
        }
        a = b;
    }

    for (int i = 1023; i >= 0; i--)
        if (a[i]) {
            cout << i << " ";
            break;
        }
    for (int i = 0; i < 1024; i++)
        if (a[i]) {
            cout << i << " ";
            break;
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
