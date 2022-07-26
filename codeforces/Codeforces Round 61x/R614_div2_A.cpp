#include <string.h>
#include <stdio.h>
#include <math.h>
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
    int n, s, k;
    cin >> n >> s >> k;
    vector<int> v(k);
    set<int> ss;
    for (int &x: v) {
        cin >> x;
        ss.insert(x);
    }
    int r = 1 << 30;
    for (int i = max(1, s - 2000); i <= min(n, s + 2000); i++) {
        if(!ss.count(i))r = min(r, ab(s - i));
    }
    cout << r << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
