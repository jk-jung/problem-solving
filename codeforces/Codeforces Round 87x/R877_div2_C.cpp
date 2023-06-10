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
    int n, m;
    cin >> n >> m;
    if (n > 4) {
        for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < m; j++) {
                cout << i * m + j + 1 << " ";
            }
            cout << endl;
        }
        for (int i = 1; i < n; i += 2) {
            for (int j = 0; j < m; j++) {
                cout << i * m + j + 1 << " ";
            }
            cout << endl;
        }
        cout << endl;
    } else {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < m; j++) {
                cout << j * 4 + i + 1 << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
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
