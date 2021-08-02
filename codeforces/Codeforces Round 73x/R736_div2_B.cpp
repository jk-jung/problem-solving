#include <string.h>
#include <stdio.h>
#include <math.h>
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
    int n, r = 0;
    cin >> n;
    string a, b;
    cin >> a >> b;

    for (int i = 0; i < n; i++) {
        if (b[i] == '1') {
            if (a[i] == '0') {
                r++;
                a[i] = '2';
            } else if (i - 1 >= 0 && a[i - 1] == '1') {
                r++;
                a[i - 1] = '2';
            } else if (i + 1 < n && a[i + 1] == '1') {
                r++;
                a[i + 1] = '2';
            }
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
