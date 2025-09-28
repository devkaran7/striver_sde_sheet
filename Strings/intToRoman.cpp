#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        // Map to store the values of Roman numerals
        std::unordered_map<char, int> values = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        // Initialize total with the value of the last character
        int total = values[s.back()];
        
        // Iterate from the second-to-last character to the first
        for (int i = s.length() - 2; i >= 0; --i) {
            // If current value is less than the value to its right, subtract
            if (values[s[i]] < values[s[i + 1]]) {
                total -= values[s[i]];
            } 
            // Otherwise, add
            else {
                total += values[s[i]];
            }
        }
        
        return total;
    }
};

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string intToRoman(int num) {
        // Create lookup tables sorted from largest to smallest value
        std::vector<int> values = {
            1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
        };
        std::vector<std::string> symbols = {
            "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
        };
        
        std::string result = "";
        
        // Greedily subtract the largest possible values
        for (int i = 0; i < values.size(); ++i) {
            // While the number is large enough for the current symbol
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }
        
        return result;
    }
};
