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
    int x;
    cin >> s >> x;
    if(s == "ABC") {
        cout << (x < 2000 ? "YES\n" : "NO\n");
    }
    if(s == "ARC") {
        cout << (x < 2800 ? "YES\n" : "NO\n");
    }
    if(s == "AGC") {
        cout << (x >= 1200 ? "YES\n" : "NO\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}