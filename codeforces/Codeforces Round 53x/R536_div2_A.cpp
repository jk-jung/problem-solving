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
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &s: v)cin >> s;
    int r = 0;
    for (int i = 1; i < n - 1; i++)
        for (int j = 1; j < n - 1; j++) {
            if (v[i][j] != 'X')continue;
            if (v[i - 1][j - 1] != 'X')continue;
            if (v[i - 1][j + 1] != 'X')continue;
            if (v[i + 1][j - 1] != 'X')continue;
            if (v[i + 1][j + 1] != 'X')continue;
            r++;
        }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
