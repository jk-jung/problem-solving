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
    string a, b;
    cin >> a >> b;
    map<char, int> ck;
    for (char x: a)ck[x]++;
    string c = a;
    sort(c.begin(), c.end());

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != c[i]) {
            for (int j = a.size() - 1; j >= 0; j--) {
                if (a[j] == c[i]) {
                    swap(a[i], a[j]);
                    break;
                }
            }
            break;
        }
    }

    cout << (a < b ? a : "---") << endl;
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
