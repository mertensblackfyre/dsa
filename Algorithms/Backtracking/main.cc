
#include <iostream>
#include <stack>
#include <vector>

void dfs(int i, std::stack<int> &stack, std::vector<int> nums);

int main() {

  std::vector<int> nums = {1, 2, 3};
  std::stack<int> stack;
  dfs(0, stack, nums);
  return 0;
}

void dfs(int i, std::stack<int> &stack, std::vector<int> nums) {

  if (i >= nums.size()) {

    std::cout << nums[i];
    return;
  }

  stack.push(nums[i]);
  dfs(i + 1, stack, nums);

  stack.pop();
  dfs(i - 1, stack, nums);
};
