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
    int a = s.rfind('1');
    int b = s.find('0');

    if (a == string::npos && b == string::npos) {
        cout << n << endl;
    } else if (a == string::npos) {
        cout << b + 1 << endl;
    } else if (b == string::npos) {
        cout << n - a << endl;
    } else if(a < b){
        cout << b - a + 1 << endl;
    } else {
        cout << 1 << endl;
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