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
    int a, b, c;
    cin >> a >> b >> c;


    if (a + b + c == a) cout << string(a + 1, '0') << endl;
    else if (a + b + c == c) cout << string(c + 1, '1') << endl;
    else {
        string r = string(a + 1, '0') + string(c + 1, '1');
        b--;
        while (b--) r += (r.back() == '0' ? '1' : '0');
        cout << r << endl;
    }
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
