class Solution {
    List<List<Integer>> sets;
    public void find_set(int[] nums, int ind, int n, List<Integer>CurrentSubset){
        if(ind >= n){
            sets.add(new ArrayList<>(CurrentSubset));
            return;
        }
        find_set(nums, ind+1, n, CurrentSubset);
        CurrentSubset.add(nums[ind]);
        find_set(nums, ind+1, n, CurrentSubset);
        CurrentSubset.remove(CurrentSubset.size() - 1);
    }
    public List<List<Integer>> subsets(int[] nums) {
        int n = nums.length;
        sets = new ArrayList<>();
        find_set(nums, 0, n, new ArrayList<>());
        return sets;
    }
}