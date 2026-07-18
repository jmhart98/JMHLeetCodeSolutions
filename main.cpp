#include <iostream>
#include <string>

using namespace std;

// This program currently has solutions for the following LeetCode problems:
// 1. Two Sum
// 1979. Find Greatest Common Divisor of Array


// Solution code for Problem 1. Two Sum
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

// Solution code for Problem 1979. Find Greatest Common Divisor of Array
string getProblem1979Solution() {
    return R"(class Solution {
public:
    int findGCD(vector<int>& nums) {
        // Step 1: find the smallest and largest values in nums
        int smallest = nums[0];
        int largest = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < smallest) {
                smallest = nums[i];
            }
            if (nums[i] > largest) {
                largest = nums[i];
            }
        }

        // Step 2: compute GCD of smallest and largest using the Euclidean Algorithm
        int a = largest;
        int b = smallest;

        while (b != 0) {
            int remainder = a % b;
            a = b;
            b = remainder;
        }

        // Step 3: a now holds the GCD
        return a;
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
    } else if (choice == "1979") {
        cout << "\n--- Problem 1979: Find Greatest Common Divisor of Array ---\n\n";
        cout << getProblem1979Solution() << endl;
    } else {
        cout << "\nSorry, I don't have a solution stored for problem \""
             << choice << "\" yet.\n";
    }

    return 0;
}
