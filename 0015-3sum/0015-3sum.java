class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> ans = new HashSet<List<Integer>>();
        Integer n = nums.length;
        Arrays.sort(nums);
        
        for(int i=0; i<n;){
            int l=i+1,r=n-1;
            while(l<r){
                int sum = nums[l] + nums[r] + nums[i];
                if(sum == 0){
                    List<Integer> v = new ArrayList();
                    v.add(nums[i]);
                    v.add(nums[l]);
                    v.add(nums[r]);
                    ans.add(v);
                    l++; r--;
                }
                if(sum < 0) l++;
                if(sum > 0) r--;
            }
            i++;
            while(i<n && nums[i] == nums[i-1]) i++;
        }
        List<List<Integer>> s = new ArrayList<List<Integer>>();
        s.addAll(ans);
        return s;
    }
}