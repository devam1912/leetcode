public class Solution
{
    public int MinMoves2(int[] nums)
    {
        Array.Sort(nums);

        int n = nums.Length;
        int median = nums[n / 2];

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans += Math.Abs(nums[i] - median);
        }

        return ans;
    }
}