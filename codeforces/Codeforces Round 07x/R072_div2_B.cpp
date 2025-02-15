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

string a, b;

void solve() {
    int n;
    cin >> n;
    int last = 1 << 30;
    ll streak = 0;
    ll r = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (last != x) {
            r += streak * (streak + 1) / 2;
            streak = 1;
        } else {
            streak++;
        }
        last = x;
    }
    r += streak * (streak + 1) / 2;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
