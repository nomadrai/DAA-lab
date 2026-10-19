#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void generatecombinations(string &digits, int ind, vector<string> &ans, string &str, unordered_map<char, string> &keypad)
    {
        if(str.size() == digits.size())
        {
            ans.push_back(str);
            return;
        }

        string t = keypad[digits[ind]];
        for(int i = 0; i < t.size(); i++)
        {
            str += t[i];
            generatecombinations(digits, ind + 1, ans, str, keypad);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if(digits.empty())
            return {};

        unordered_map<char, string> keypad;
        keypad['2'] = "abc";
        keypad['3'] = "def";
        keypad['4'] = "ghi";
        keypad['5'] = "jkl";
        keypad['6'] = "mno";
        keypad['7'] = "pqrs";
        keypad['8'] = "tuv";
        keypad['9'] = "wxyz";

        vector<string> ans;
        string str = "";
        int ind = 0;

        generatecombinations(digits, ind, ans, str, keypad);
        return ans;
    }
};

int main()
{
    string digits;

    cout << "Enter digits (2-9): ";
    cin >> digits;

    Solution sol;
    vector<string> result = sol.letterCombinations(digits);

    cout << "Output: [";
    for(int i = 0; i < result.size(); i++)
    {
        cout << "\"" << result[i] << "\"";
        if(i < result.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
