#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
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
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> k;

    cout << n * 3 << endl;

    for(int i=1;i<=n;i+=2) {
        int a = i;
        int b = i + 1;

        for(int j=0;j<2;j++){
            cout <<"1 " << a << " " << b << "\n";
            cout <<"2 " << a << " " << b << "\n";
            cout <<"1 " << a << " " << b << "\n";
        }
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
