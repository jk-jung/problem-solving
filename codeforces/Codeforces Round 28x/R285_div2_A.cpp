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

int get_point(int p, int t) {
    return max(3 * p / 10, p - p / 250 * t);
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int m = get_point(a, c);
    int v = get_point(b, d);
    if (m == v) cout << "Tie" << endl;
    else if (m > v) cout << "Misha" << endl;
    else cout << "Vasya" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
