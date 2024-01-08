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
    vi a(400), b(400);
    for (int i = 0; i < n; i++) {
        string s;
        int x, y;
        cin >> s >> x >> y;
        if (s[0] == 'M')for (int j = x; j <= y; j++)a[j]++;
        else for (int j = x; j <= y; j++)b[j]++;
    }
    int r = 0;
    for (int i = 0; i < 400; i++)r = max(r, min(a[i], b[i]));
    cout << r * 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
