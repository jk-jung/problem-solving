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

int a[55][55];

void solve() {
    int n, c = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++, c++) {
                a[i][j] = (c % 2 == 0 ? c / 2 + 1 : n * n - c / 2);
            }
        } else {
            for (int j = n - 1; j >= 0; j--, c++) {
                a[i][j] = (c % 2 == 0 ? c / 2 + 1 : n * n - c / 2);
            }
        }
        for (int j = 0; j < n; j++)cout << a[i][j] << " ";
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
