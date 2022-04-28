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
    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 0; i <= b; i++) {
        int x = (a + b - i) / (b - i + 1);
        while (a > 0 && x > 0) {
            cout << 'R';
            a--;
            x--;
            n--;
        }
        if(i != b)cout << 'B',n--;
    }
    assert(a == 0);
    assert(n == 0);
    cout << endl;
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
