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
    vi v(n);
    for (int &x: v)cin >> x;
    vi c(3);
    sort(v.begin(), v.end());
    for (int x: v)c[x - v[0]]++;
    int m = min(c[0], c[2]);
    if (c[2] == 0 || (n - m * 2 < c[0] + c[2] + c[1] % 2)) {
        cout << n - m * 2 << endl;
        for (int i = 0; i < c[0] - m; i++)cout << v[0] << " ";
        for (int i = 0; i < c[1] + m * 2; i++)cout << v[0] + 1 << " ";
        for (int i = 0; i < c[2] - m; i++)cout << v[0] + 2 << " ";
    } else {
        cout << c[0] + c[2] + c[1] % 2 << endl;
        for (int i = 0; i < c[0] + c[1] / 2; i++)cout << v[0] << " ";
        for (int i = 0; i < c[1] % 2; i++)cout << v[0] + 1 << " ";
        for (int i = 0; i < c[2] + c[1] / 2; i++)cout << v[0] + 2 << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
