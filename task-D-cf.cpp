#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
void make_for_pars(std::vector<std::string>& for_pars, std::vector<std::string>& ans, std::string& s) {
    int i = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '.') ans.push_back(".");
        else {
            ans.push_back("_");
            std::string s_temp = "";
            while (i < s.size() && s[i] != '.') {
                s_temp += s[i];
                i++;
            }
            if (i < s.size() && s[i] == '.') ans.push_back(".");
            if (i == s.size() && s[i - 1] == '.') ans.push_back(".");
            for_pars.push_back(s_temp);
        }

    }
}
std::string make_res(std::vector<std::string>& for_pars, std::vector<std::string>& ans, std::string& s) {
    int i = 0;
    int j = 0;
    std::sort(for_pars.begin(), for_pars.end()); // Нужно было реализовать используя бор - работает за О(длина текста), а  std::sort - за klogk * (длина самого длинного слова), k - число слов
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == "_") {
            ans[i] = for_pars[j];
            j++;
        }
    }
    std::string res = "";
    for (int i = 0; i < ans.size(); i++) {
        res += ans[i];
    }
    return res;
}
int main()
{
    std::string s;
    std::cin >> s;
    std::vector<std::string> for_pars;
    std::vector<std::string> ans;
    make_for_pars(for_pars, ans, s);
    std::string res = make_res(for_pars, ans, s);
    std::cout << res;
}
