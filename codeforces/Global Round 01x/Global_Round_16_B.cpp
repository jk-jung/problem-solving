#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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
    string s;
    cin >> s;

    int a = 0, b = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i > 0 && s[i] == s[i - 1]) continue;
        if (s[i] == '0') a++;
        else b++;
    }
    if (a == 0) {
        cout << "0\n";
    } else if (a == 1) {
        cout << "1\n";
    } else if (b == 0) {
        cout << "1\n";
    } else {
        cout << "2\n";
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
