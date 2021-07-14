#include<iostream>
#include <vector>
#include<string>

using namespace std;


vector<int> manacher_algorithm(string s) {
    string t = "";
    for (int i = 0; i < (int) s.size(); i++) {
        t += "#";
        t += s[i];
    }
    t += '#';

    int n = t.size();
    vector<int> d(n);
    int pivot = 0;
    int max_index = 0;

    for (int i = 1; i < n; i++) {
        if (i <= max_index)
            d[i] = min(max_index - i, d[pivot * 2 - i]);

        while (0 <= i - d[i] && i + d[i] < n && t[i - d[i]] == t[i + d[i]])
            d[i]++;
        d[i]--;

        if (max_index < i + d[i]) {
            max_index = i + d[i];
            pivot = i;
        }
    }
    return d;
}

string longest_palindrome(string s) {
    if (s.size() == 0)return "";
    vector<int> d = manacher_algorithm(s);
    int k = 0;
    for (int i = 0; i < (int) d.size(); i++)
        k = max(k, d[i]);

    for (int i = 0; i < (int) d.size(); i++)
        if (d[i] == k) {
            if (i % 2 == 0) {
                int center = (i - 1) / 2;
                int radius = d[i] / 2;
                return s.substr(center - radius + 1, radius * 2);
            } else {
                int center = i / 2;
                int radius = d[i] / 2;
                return s.substr(center - radius, radius * 2 + 1);
            }
        }
}