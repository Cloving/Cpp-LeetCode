class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> vec;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                vec.push_back("FizzBuzz");
            } else if (i % 3 == 0) {
                vec.push_back("Fizz");
            } else if (i % 5 == 0) {
                vec.push_back("Buzz");
            } else {
                /* 利用to_string()将int转成string */
                vec.push_back(to_string(i));
            }
        }
        return vec;
    }
};