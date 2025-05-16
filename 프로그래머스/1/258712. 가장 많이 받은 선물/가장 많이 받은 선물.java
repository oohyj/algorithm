import java.util.*;

class Solution {
    public int solution(String[] friends, String[] gifts) {
        int n = friends.length;
        Map<String, Integer> giftDict = new HashMap<>();
        int[][] giftTable = new int[n][n];
        int[] giftScore = new int[n];
        int[] totalGift = new int[n];

        // 친구 이름 → 인덱스 매핑
        for (int i = 0; i < n; i++) {
            giftDict.put(friends[i], i);
        }

        // 선물 기록 분석
        for (String gift : gifts) {
            String[] parts = gift.split(" ");
            String a = parts[0];
            String b = parts[1];

            int from = giftDict.get(a);
            int to = giftDict.get(b);

            giftTable[from][to]++;
            giftScore[from]++;
            giftScore[to]--;
        }

        // 다음 달 받을 선물 계산
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                if (giftTable[i][j] > giftTable[j][i]) {
                    totalGift[i]++;
                } else if (giftTable[i][j] == giftTable[j][i]) {
                    if (giftScore[i] > giftScore[j]) {
                        totalGift[i]++;
                    }
                }
            }
        }

        // 최댓값 반환
        int maxGift = 0;
        for (int count : totalGift) {
            maxGift = Math.max(maxGift, count);
        }

        return maxGift;
    }
}