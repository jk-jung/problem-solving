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
    int n, z = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)if (s[i] == '0') z++;
    if(n % 2 && s[n/2] == '0') {
        if( z > 2)
            cout << "ALICE" << endl;
        else if(z == 2)
            cout << "DRAW" << endl;
        else
            cout << "BOB" << endl;
    }
    else {
        cout << "BOB" << endl;
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
