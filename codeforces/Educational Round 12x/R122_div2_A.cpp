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
    int n, rc =999;
    string s, r;
    cin >> s;
    for (int i = 14; i <= 999; i += 7) {
        string a = to_string(i);
        if (a.size() != s.size()) continue;
        int cnt = 0;
        for (int j = 0; j < a.size(); j++)if (a[j] != s[j])cnt++;
        if(rc > cnt) {
            rc = cnt;
            r = a;
        }
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
