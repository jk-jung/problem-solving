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

int a[100005];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];

    for (int i = 0; i < n; i++) {
        bool ok = false;

        for (int k = i + 2, c = 0; k >= 2 && c < 15; k--, c ++) {
            if(a[i] % k != 0) {
                ok = true;
                break;
            }
        }
        if(!ok) {
            cout <<"NO\n";
            return;
        }
    }

    cout <<"YES\n";

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
