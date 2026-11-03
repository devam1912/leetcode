public class Solution {
    public int MinMergedInteger(int[] nums) {
        int min = int.MaxValue;

        for (int i = 0; i < nums.Length; i += 2) {
            int merged = int.Parse(nums[i].ToString() + nums[i + 1].ToString());

            min = Math.Min(min, merged);
        }

        return min;
    }
}