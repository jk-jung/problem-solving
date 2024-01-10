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

int a[555][555];

void solve() {
    int n, k;
    cin >> n >> k;
    int r = 0;
    int t = n * n;
    k = n - k + 1;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= n - k; j--) {
            a[i][j] = t--;
            if (j == n - k) r += a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = n - k - 1; j >= 0; j--) {
            a[i][j] = t--;
        }
    }
    cout << r << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
