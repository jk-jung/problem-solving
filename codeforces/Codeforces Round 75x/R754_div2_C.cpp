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
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'a' && s[i + 1] == 'a') {
            cout << 2 << '\n';
            return;
        }
    }

    for (int i = 0; i < n - 2; i++) {
        if (s[i] == 'a' && s[i + 2] == 'a') {
            cout << 3 << '\n';
            return;
        }
    }

    for (int i = 0; i < n - 3; i++) {
        if (s[i] == 'a' && s[i + 3] == 'a' && s[i + 1] != s[i + 2]) {
            cout << 4 << '\n';
            return;
        }
    }

    for (int i = 0; i < n - 6; i++) {
        if (s[i] == 'a' && s[i + 3] == 'a' && s[i + 6] == 'a') {
            int b = 0, c = 0;
            if (s[i + 1] == 'b') b++;
            else c++;
            if (s[i + 2] == 'b') b++;
            else c++;
            if (s[i + 4] == 'b') b++;
            else c++;
            if (s[i + 5] == 'b') b++;
            else c++;

            if (b == c) {
                cout << 7 << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
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
