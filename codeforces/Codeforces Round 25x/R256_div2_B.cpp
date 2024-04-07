#include <cstring>
#include <cstdio>
#include <cmath>
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


bool check(string &a, string &b) {
    int i = 0;
    for (char x: b) {
        while (i < a.size() && a[i] != x) i++;
        if (i++ == a.size()) return false;
    }
    return true;
}

void solve() {
    string a, b;
    cin >> a >> b;


    if(check(a, b)){
        cout << "automaton";
        return;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a == b)cout << "array";
    else if (check(a, b)) cout << "both";
    else cout << "need tree";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
