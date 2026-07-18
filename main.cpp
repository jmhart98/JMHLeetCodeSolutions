#include <iostream>
#include <string>

using namespace std;

// Returns the full solution code for Problem 1 (Two Sum) as a text block,
// so we can print it out for the user.
string getProblem1Solution() {
    return R"(class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // Check if the complement was already seen
            if (seen.find(complement) != seen.end()) {
                return {seen[complement], i};
            }

            // Record this number and its index for future lookups
            seen[nums[i]] = i;
        }

        return {}; // guaranteed not to reach here per problem constraints
    }
};)";
}

int main() {
    cout << "Which LeetCode solution would you like to see? ";

    string choice;
    getline(cin, choice);

    if (choice == "1") {
        cout << "\n--- Problem 1: Two Sum ---\n\n";
        cout << getProblem1Solution() << endl;
    } else {
        cout << "\nSorry, I don't have a solution stored for problem \""
             << choice << "\" yet.\n";
    }

    return 0;
}