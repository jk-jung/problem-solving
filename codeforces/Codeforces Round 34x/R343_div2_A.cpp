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
    for (auto &i: v)cin >> i;

    int r = 0;
    for (int i = 0; i < n; i++) {
        int a = 0, b = 0;
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 'C')a++;
            if (v[j][i] == 'C')b++;
        }
        r += a * (a - 1) / 2;
        r += b * (b - 1) / 2;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
