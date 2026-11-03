public class Solution {
    public long MinimumMaxValue(int n, int index, int value) {
        if (value == 1) {
            return -1;
        }

        int p = SmallestPrimeFactor(value);

        long maxLeft = ((long)value - p) / 2;

        if (index > maxLeft) {
            return -1;
        }

        long right = (long)n - index - 1;

        // value is already the last element
        if (right == 0) {
            return value;
        }

        // First step: +p
        // Remaining steps: +2 each
        return (long)value + p + 2L * (right - 1);
    }

    private int SmallestPrimeFactor(int value) {
        if (value % 2 == 0) {
            return 2;
        }

        for (int i = 3; (long)i * i <= value; i += 2) {
            if (value % i == 0) {
                return i;
            }
        }

        // value itself is prime
        return value;
    }
}