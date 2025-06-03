import java.util.*;

class Solution {
    public long solution(int[] diffs, int[] times, long limit) {
        long left = 1;
        long right = Arrays.stream(diffs).max().getAsInt();
        long answer = right + 1;

        while (left <= right) {
            long mid = (left + right) / 2;

            if (isFinished(mid, diffs, times, limit)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return answer;
    }

    private boolean isFinished(long level, int[] diffs, int[] times, long limit) {
        int n = diffs.length;
        long totalTime = 0;

        for (int i = 0; i < n; ++i) {
            if (diffs[i] <= level) {
                totalTime += times[i];
            } else {
                long mistake = diffs[i] - level;
                long penalty = (i == 0 ? 0 : times[i - 1]);
                long timeCur = times[i];
                totalTime += mistake * (timeCur + penalty) + timeCur;
            }

            if (totalTime > limit) return false; 
        }

        return true;
    }
}