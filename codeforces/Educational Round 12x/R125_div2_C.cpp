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

    int i = 0, r = 0;
    while (i < n) {
        if (n - i <= 1)break;
        if (s[i] == ')') {
            int j = i + 1;
            while (j < n && s[j] != ')') j++;
            if (j < n && s[j] == ')') {
                i = j + 1;
                r++;
            }else break;
        } else if (s[i] == '(') {
            r++;
            i += 2;
        }
    }
    cout << r << " " << n - i << endl;
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
