import java.util.*;

class Solution {
    public int solution(int[][] points, int[][] routes) {
        int answer = 0;
        int n = routes.length;

        Map<Integer, int[]> point = new HashMap<>();
        for (int i = 0; i < points.length; ++i) {
            point.put(i + 1, points[i]);
        }

        Map<Integer, Map<String, Set<Integer>>> timeline = new HashMap<>();

        for (int i = 0; i < n; ++i) {
            int time = 0;
            int[] route = routes[i];

            for (int j = 0; j < route.length - 1; ++j) {
                int[] start = point.get(route[j]);
                int[] end = point.get(route[j + 1]);

                int r1 = start[0], c1 = start[1];
                int r2 = end[0], c2 = end[1];

                String startPos = r1 + "," + c1;
                timeline.computeIfAbsent(time, k -> new HashMap<>());
                timeline.get(time).computeIfAbsent(startPos, k -> new HashSet<>()).add(i);

                while (r1 != r2) {
                    r1 += r1 < r2 ? 1 : -1;
                    time++;
                    String pos = r1 + "," + c1;
                    timeline.computeIfAbsent(time, k -> new HashMap<>());
                    timeline.get(time).computeIfAbsent(pos, k -> new HashSet<>()).add(i);
                }

                while (c1 != c2) {
                    c1 += c1 < c2 ? 1 : -1;
                    time++;
                    String pos = r1 + "," + c1;
                    timeline.computeIfAbsent(time, k -> new HashMap<>());
                    timeline.get(time).computeIfAbsent(pos, k -> new HashSet<>()).add(i);
                }
            }
        }

        for (Map<String, Set<Integer>> posMap : timeline.values()) {
            for (Set<Integer> robotSet : posMap.values()) {
                if (robotSet.size() >= 2) {
                    answer++;
                }
            }
        }

        return answer;
    }
}