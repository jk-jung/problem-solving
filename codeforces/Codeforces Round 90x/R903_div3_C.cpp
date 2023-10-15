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

char a[1005][1005];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];
    int m = n / 2;
    int r = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            vector<char> v;
            int y = i, x = j;
            for (int k = 0; k < 4; k++) {
                v.pb(a[y][x]);
                int ny = x;
                x = n - y - 1;
                y = ny;
            }
            sort(v.begin(), v.end());
            for (char k: v)r += v.back() - k;
        }
    }
    cout << r << endl;
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
