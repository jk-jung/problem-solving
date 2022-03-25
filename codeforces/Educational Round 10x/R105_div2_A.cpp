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
    int n = s.size();
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++) {
                int v = 0;

                bool ok = true;
                for (char c: s) {
                    string t;
                    if (c == 'A') v += (i == 0 ? 1 : -1);
                    if (c == 'B') v += (j == 0 ? 1 : -1);
                    if (c == 'C') v += (k == 0 ? 1 : -1);
                    if (v < 0) {
                        ok = false;
                    }
                }
                if(ok && v == 0) {
                    cout <<"YES\n";
                    return;
                }
            }
    cout <<"NO\n";
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
