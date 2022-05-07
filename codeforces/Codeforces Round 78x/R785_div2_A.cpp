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
    int tot = 0, r;
    for (char x: s)tot += (x - 'a') + 1;

    if (s.size() % 2 == 0)r = tot;
    else r = max(tot - s[0] + 'a' - 1, tot - s.back() + 'a' - 1);

    int b = tot - r;

    if(r > b) {
        cout <<"Alice " << r - b<< endl;
    }else {
        cout <<"Bob " << b - r << endl;
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
