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

int r[105][105];
int n;

void solve() {
    cin >> n;
    memset(r, 0, sizeof(r));

    int m = (n - 1) / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = (i + j + 1) % n;
            int v = (j < m ? 1 : -1);
            r[i][x] = v;
            r[x][i] = -v;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)cout << r[i][j] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}