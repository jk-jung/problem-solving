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
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        char x = tolower(a[i]);
        char y = tolower(b[i]);
        if (x < y) {
            cout << -1;
            return;
        }
        if (x > y) {
            cout << 1;
            return;
        }
    }
    cout << 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
