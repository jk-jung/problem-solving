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
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int r = 0;
    for (int i = 0; i < y; i++)if (s[i] == '1') r++;
    for (int i = y + 1; i < x; i++)if (s[i] == '1') r++;
    if (s[y] == '0') r++;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
