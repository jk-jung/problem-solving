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
    int n, a = 0, b = 0;
    string s;
    cin >> n >> s;

    s += 'W';
    for (char x: s) {
        if (x == 'W') {
            if(a == 0 && b == 0)continue;
            if (a > 0 && b > 0);
            else {
                cout << "NO\n";
                return;
            }
            a = b = 0;
        } else if (x == 'B') a++;
        else b++;
    }
    cout << "YES\n";
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
