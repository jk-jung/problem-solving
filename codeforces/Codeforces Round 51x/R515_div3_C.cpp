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
    int s = 1, e = 0;
    s = e = 0;
    map<int, int> ck;
    while (n--) {
        char x;
        int y;
        cin >> x >> y;
        if (x == 'R') ck[y] = ++e;
        else if (x == 'L') ck[y] = --s;
        else cout << min(ck[y] - s, e - ck[y]) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
