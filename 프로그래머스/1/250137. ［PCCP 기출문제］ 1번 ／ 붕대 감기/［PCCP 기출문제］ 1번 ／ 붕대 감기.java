import java.util.*;

class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int limit = health; // 최대 체력 저장
        int sequence = 0;   // 연속 성공 횟수
        int currentTime = 1; // 현재 시간

        Queue<int[]> info = new LinkedList<>();
        for (int[] attack : attacks) {
            info.offer(new int[]{attack[0], attack[1]});
        }

        while (!info.isEmpty() || currentTime <= attacks[attacks.length - 1][0]) {
            if (!info.isEmpty() && info.peek()[0] == currentTime) {
                // 공격 받는 경우
                health -= info.peek()[1];
                sequence = 0;
                info.poll();
            } else {
                // 붕대 감기 성공
                sequence++;
                if (sequence == bandage[0]) {
                    health += bandage[2];
                    sequence = 0;
                }
                health = Math.min(health + bandage[1], limit);
            }

            if (health <= 0) {
                return -1;
            }

            currentTime++;
        }

        return health;
    }
}