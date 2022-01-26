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

string v[555];

void solve() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    for (int i = 0; i < n; i++)cin >> v[i];
    r--;
    c--;
    int b = 0, cc = 0;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)if (v[i][j] == 'B') b++;
    for (int i = 0; i < n; i++)if (v[i][c] == 'B') cc = 1;
    for (int j = 0; j < m; j++)if (v[r][j] == 'B') cc = 1;


    int t = 0;
    if (v[r][c] == 'B') t = 0;
    else if (b == 0) t = -1;
    else if (cc)t = 1;
    else t = 2;
    cout << t << endl;
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
