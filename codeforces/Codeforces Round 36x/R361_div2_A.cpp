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


void solve() {
    int n;
    string s;
    cin >> n >> s;
    bool a0 = s.find('0') != -1;
    bool a1 = s.find('1') != -1;
    bool a2 = s.find('2') != -1;
    bool a3 = s.find('3') != -1;
    bool a4 = s.find('4') != -1;
    bool a6 = s.find('6') != -1;
    bool a7 = s.find('7') != -1;

    bool a9 = s.find('9') != -1;

    cout << ((a1 && a9) || (a3 && a7) || (a0 && a2) || (a0 && a1) || (a0 && a3) || (a3 && a4 && a9) ||
             (a1 && a6 && a7) || (a2 && a7 && a9)|| (a2 && a6 && a7) || (a2 && a4 && a9)? "YES" : "NO");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
