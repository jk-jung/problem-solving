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

    int ii = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0')ii = i;
        else break;
    }
    s = s.substr(ii + 1);
    if (s.find('.') != string::npos) {
        while (s.back() == '0') s.pop_back();
        if (s.back() == '.') s.pop_back();
    }
    if (s.empty()) {
        cout << "0";
        return;
    }
    if (s[0] == '.') {
        int c = 0, flag = 0;
        for (int i = 1; i < s.size(); i++) {
            if (flag == 0)c--;
            if (s[i] != '0' && flag == 0) {
                flag = 1;
            }
            if (flag == 1) {
                cout << s[i];
                if (i + 1 < s.size())cout << '.';
                flag = 2;
            } else if (flag == 2)cout << s[i];
        }
        if(c)
            cout << "E" << c;
        return;
    } else {
        int c = 0, flag = 0;
        while (s.back() == '0')s.pop_back(), c++;
        if (s.size() == 1) {
            cout << s;
            if (c) cout << "E" << c << endl;
            return;
        }
        cout << s[0] << ".";


        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '.') {
                flag = 1;
                continue;
            }
            if (flag == 0) c++;
            cout << s[i];
        }
        if(c)cout << "E" << c;
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
