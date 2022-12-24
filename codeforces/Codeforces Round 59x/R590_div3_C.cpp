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
    string v[2];
    cin >> n >> v[0] >> v[1];
    int last = 0;
    for (int i = 0; i < n; i++) {
        char x = v[last][i];
        char y = v[last ^ 1][i];
        if ('1' <= x && x <= '2') { ;
        } else if ('3' <= y && y <= '6') {
            last = last ^ 1;
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << (last == 1 ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
