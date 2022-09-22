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

int a[205];
int b[205];
int im[205][205];
int n, m;

bool check(int k) {
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int j = 0; j < m; j++) {
            if (im[i][j])continue;
            if (((a[i] & b[j]) >> k & 1) == 0) {
                ok = true;
                break;
            }
        }
        if (!ok) return false;
    }
    return true;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < m; i++)cin >> b[i];

    int r = 0;
    for (int k = 30; k >= 0; k--) {
        if (check(k)){
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if ((a[i] & b[j]) >> k & 1)im[i][j] = 1;
                }
            }
        }
        else {
            r |= 1 << k;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
