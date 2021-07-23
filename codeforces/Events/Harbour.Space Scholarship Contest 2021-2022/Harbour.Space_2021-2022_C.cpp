#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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

    int r = 10;
    for (int i = 0, a = 0, b = 0, bb = 5; i < 10; i++) {
        if (i % 2 == 0 && (s[i] == '1' || s[i] == '?')) a++;
        if (i % 2 == 1 && s[i] == '1') b++;
        if (i % 2 == 1) bb--;

        if (a > b + bb) r = min(r, i + 1);
    }
    for (int i = 0, a = 0, b = 0, aa = 5; i < 10; i++) {
        if (i % 2 == 0 && s[i] == '1') a++;
        if (i % 2 == 1 && (s[i] == '1' || s[i] == '?')) b++;
        if (i % 2 == 0) aa--;

        if (b > a + aa) r = min(r, i + 1);
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
