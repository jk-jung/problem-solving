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

vector<vector<ll>> v(256, vector<ll>(256));
void solve() {
    int n, m;
    cin >> n >> m;

    cout << n * m << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)cout << v[i][j] << " ";
        cout << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int t = 0, n = 256, m = 256;
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < m; j += 2) {
            v[i][j] = t++;
            v[i][j + 1] = t++;
            v[i + 1][j] = t++;
            v[i + 1][j + 1] = t++;
        }

    }

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
