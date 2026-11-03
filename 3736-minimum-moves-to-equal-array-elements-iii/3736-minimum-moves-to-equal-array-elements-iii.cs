public class Solution {
    public int MinMoves(int[] nums) {
        int max = 0;

        for (int i = 0; i < nums.Length; i++) {
            max = Math.Max(max, nums[i]);
        }

        int moves = 0;

        for (int i = 0; i < nums.Length; i++) {
            moves += max - nums[i];
        }

        return moves;
    }
}