#include <iostream>
#include <vector>

void dfs(int i, std::vector<bool> &pick, std::vector<int> &stack,
         std::vector<int> nums, std::vector<std::vector<int>> &res);

int main() {

  std::vector<int> nums = {1, 2, 3};

  std::vector<std::vector<int>> res;
  std::vector<bool> pick(nums.size(), false);
  std::vector<int> stack;
  dfs(0, pick, stack, nums, res);

  for (auto x : res) {
    for (auto y : x) {
      std::cout << y;
    }
    std::cout << std::endl;
  }
  return 0;
}

void dfs(int i, std::vector<bool> &pick, std::vector<int> &stack,
         std::vector<int> nums, std::vector<std::vector<int>> &res) {

  if (stack.size() == nums.size()) {
    res.push_back(stack);
    return;
  }
  for (size_t i = 0; i < nums.size(); i++) {
    if (!pick[i]) {
      pick[i] = true;
      stack.push_back(nums[i]);

      dfs(i, pick, stack, nums, res);
      pick[i] = false;

      stack.pop_back();
    }
  }
};
