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
    int n, k;
    cin >> n >> k;
    set<int> ck;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        ck.insert(x);
    }
    int last = 0;
    while (k--) {
        int m = *ck.rbegin();
        while (ck.count(last))last++;
        int x = (m + last + 1) / 2;

        if(m + 1  == x) {
            cout <<  x + k + 1 << endl;
            return;
        }

        if(ck.count(x))break;
        ck.insert(x);
    }
    cout << ck.size() << endl;
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
