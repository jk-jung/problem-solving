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
    string s;
    cin >> s;


    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '?') {
            char x = i == 0 ? 'A' : s[i - 1];
            char z = i + 1 == s.length() ? 'A' : s[i + 1];
            char y = 'a';
            for (; y <= 'c'; y++) {
                if (x != y && y != z) {
                    s[i] = y;
                    break;
                }
            }
            if (y == 'd') {
                cout << "-1\n";
                return;
            }
        }else if(i && s[i-1] == s[i]) {
            cout << "-1\n";
            return;
        }
    }
    cout << s << endl;

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
