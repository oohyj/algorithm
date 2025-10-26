import java.util.*;

class Solution {
    public int[] solution(int N, int[] stages) {
        int[] stay = new int[N + 2]; 
        for (int s : stages) {
            if (1 <= s && s <= N + 1) {
                stay[s]++;
            }
        }

      
        int total = stages.length; 
        double[] fail = new double[N + 1]; 
        for (int stage = 1; stage <= N; stage++) {
            if (total == 0) {
                fail[stage] = 0.0;
            } else {
                fail[stage] = (double) stay[stage] / total;
            }
            total -= stay[stage]; 
        }

      
        Integer[] order = new Integer[N];
        for (int i = 0; i < N; i++) order[i] = i + 1;

        Arrays.sort(order, (a, b) -> {
            if (fail[b] > fail[a]) return 1;
            if (fail[b] < fail[a]) return -1;
            return Integer.compare(a, b);
        });


        int[] answer = new int[N];
        for (int i = 0; i < N; i++) answer[i] = order[i];
        return answer;
    }
}