#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))


void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int r = -30;
    if(a)r = max(r, (a - 1) / 2 * 3);
    if(b)r = max(r, (b - 1) / 2 * 3 + 1);
    if(c)r = max(r, (c - 1) / 2 * 3 + 2);
    cout << r + 30;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
