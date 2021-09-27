#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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

void rotate(int x) {
    int s = r[n-1][x];
    for(int i=n-1;i>=1;i--){
        r[i][x] = r[i-1][x];
    }
    r[0][x] = s;
}

void solve() {
    cin >> n;
    if (n == 2) {
        cout << -1 << '\n';
        return;
    }

    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)r[i][j] = i * n + j + 1;
    for (int j = 1; j < n; j++) {
        for (int k = 0; k < j; k++)rotate(j);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)cout << r[i][j] << " ";
        cout << endl;
    }
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
