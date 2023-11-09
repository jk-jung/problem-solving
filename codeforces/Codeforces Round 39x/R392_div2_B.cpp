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
    string s;
    cin >> s;
    map<char, int> r;

    while (true) {
        bool done = true;
        char last = ' ';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '!')continue;
            for (int j = i; j < s.size(); j += 4) {
                if (s[j] == '!')s[j] = s[i], done = false, r[s[i]]++;
            }
            for (int j = i; j >= 0; j -= 4) {
                if (s[j] == '!')s[j] = s[i], done = false, r[s[i]]++;
            }
        }

        if (done)break;
    }
    cout << r['R'] << " " << r['B'] << " " << r['Y'] << " " << r['G'] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
