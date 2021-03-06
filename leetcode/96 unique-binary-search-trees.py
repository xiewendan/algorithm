# -*- coding: utf-8 -*-

# __author__ = xiaobao
# __date__ = 2019/11/11 22:32:50

# desc: desc

# 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

# 示例:

# 输入: 3
# 输出: 5
# 解释:
# 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

#    1         3     3      2      1
#     \       /     /      / \      \
#      3     2     1      1   3      2
#     /     /       \                 \
#    2     1         2                 3

# 来源：力扣（LeetCode）
# 链接：https://leetcode-cn.com/problems/unique-binary-search-trees
# 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 思路
## 递归
# f(n) = (0->n-1) f(i)*f(n-1-i)

# 复杂度
## 时间复杂度：o(n*n)
## 空间复杂度：o(n)

# 代码
class Solution:
    # def numTrees(self, n: int) -> int:
    def numTrees(self, n: int) -> int:
        if n == 0:
            return 0
        dp = [0] * (n+1)
        dp[0] = 1
        dp[1] = 1
        for i in range(2, n+1):
            for j in range(i):
                dp[i] += dp[j] * dp[i-j-1]
        
        return dp[n]
    
# 边界
solution = Solution()
# 0
assert(solution.numTrees(0) == 0)
assert(solution.numTrees(1) == 1)
assert(solution.numTrees(2) == 2)
assert(solution.numTrees(3) == 5)