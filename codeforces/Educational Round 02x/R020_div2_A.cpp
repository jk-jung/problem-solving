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

int a[105][105];

void solve() {
    int n, k;
    cin >> n >> k;
    if (k > n * n) {
        cout << -1;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (!k)continue;
                if (i == j)k--, a[i][j] = 1;
                else if (k >= 2)k -= 2, a[i][j] = a[j][i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)cout << a[i][j] << " ";
            cout << endl;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
