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
bool ck = false;

bool sf(char a, char b) {
    if (ck) {
        if (a == 'b' && b == 'c') return false;
        if (a == 'c' && b == 'b') return true;
    }
    return a < b;
}

void solve() {
    string a, b;
    cin >> a >> b;
    ck = false;
    if (a.find('a') != string::npos && b[1] == 'b' && b[2] == 'c') ck = true;

    sort(a.begin(), a.end(), sf);
    cout << a << endl;
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
