import java.util.*;

public class Main {
    static int A, B, C;
    static boolean[][][] visited = new boolean[201][201][201];
    static TreeSet<Integer> answer = new TreeSet<>();

    static class State {
        int a, b, c;
        State(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }

    static void bfs() {
        Queue<State> q = new LinkedList<>();
        q.add(new State(0, 0, C));
        visited[0][0][C] = true;

        while (!q.isEmpty()) {
            State cur = q.poll();
            int a = cur.a, b = cur.b, c = cur.c;

            if (a == 0) answer.add(c);

            // 6가지 물 붓기
            pour(q, a, b, c, 0, 1, A, B); // A → B
            pour(q, a, b, c, 0, 2, A, C); // A → C
            pour(q, a, b, c, 1, 0, B, A); // B → A
            pour(q, a, b, c, 1, 2, B, C); // B → C
            pour(q, a, b, c, 2, 0, C, A); // C → A
            pour(q, a, b, c, 2, 1, C, B); // C → B
        }
    }

    // 물 붓기 로직
    static void pour(Queue<State> q, int a, int b, int c, int from, int to, int fromCap, int toCap) {
        int[] amounts = {a, b, c};
        int move = Math.min(amounts[from], toCap - amounts[to]);

        amounts[from] -= move;
        amounts[to] += move;

        int na = amounts[0], nb = amounts[1], nc = amounts[2];

        if (!visited[na][nb][nc]) {
            visited[na][nb][nc] = true;
            q.add(new State(na, nb, nc));
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        A = sc.nextInt();
        B = sc.nextInt();
        C = sc.nextInt();

        bfs();

        for (int val : answer) {
            System.out.print(val + " ");
        }
    }
}