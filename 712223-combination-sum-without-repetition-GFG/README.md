# [Combination Sum Without Repetition](https://www.geeksforgeeks.org/problems/combination-sum-ii-1664263832/1)
## Medium
Given an array&nbsp;arr[]&nbsp;and a&nbsp;target, your task is to find all&nbsp;unique&nbsp;combinations in the array where the sum of the elements is equal to target. Each element in arr[] can be used at most once in the combination.
Note:&nbsp;You can return your answer in&nbsp;any&nbsp;order, the driver code will print them in sorted order.Test cases are generated such that number of unique combination does not exceed 106.
Examples:
Input: arr[] = [1, 2, 3], target = 5
Output: [[2, 3]]
Explanation: There is only one unique combinations whose sum is equal to the target.
Input: arr[] = [1, 3, 2, 2, 2], target = 4
Output: [[1, 3], [2, 2]]
Explanation: There are two unique possible combinations whose sum is equal to target.
Constraints:1 ≤&nbsp;arr.size() ≤&nbsp;1001 ≤ arr[i] ≤&nbsp;501 ≤ target ≤&nbsp;30