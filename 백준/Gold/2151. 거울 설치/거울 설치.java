import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static char[][] map;
    static int[] dx = {-1, 1, 0, 0}; // 위, 아래, 왼, 오른
    static int[] dy = {0, 0, -1, 1};
    static final int INF = 1_000_000_000;

    static class Node {
        int x, y, dir, cost;
        Node(int x, int y, int dir, int cost) {
            this.x = x;
            this.y = y;
            this.dir = dir;
            this.cost = cost;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        map = new char[N][N];
        List<int[]> doors = new ArrayList<>();

        for (int i = 0; i < N; ++i) {
            String line = br.readLine();
            for (int j = 0; j < N; ++j) {
                map[i][j] = line.charAt(j);
                if (map[i][j] == '#') {
                    doors.add(new int[]{i, j});
                }
            }
        }

        int sx = doors.get(0)[0];
        int sy = doors.get(0)[1];
        int ex = doors.get(1)[0];
        int ey = doors.get(1)[1];

      
        int[][][] dist = new int[N][N][4];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                Arrays.fill(dist[i][j], INF);
            }
        }

        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(n -> n.cost));


        for (int d = 0; d < 4; ++d) {
            dist[sx][sy][d] = 0;
            pq.offer(new Node(sx, sy, d, 0));
        }

        while (!pq.isEmpty()) {
            Node cur = pq.poll();

            int x = cur.x;
            int y = cur.y;
            int dir = cur.dir;
            int cost = cur.cost;

           
            if (cost > dist[x][y][dir]) continue;

       
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (map[nx][ny] == '*') continue; // 벽

            
            if (cost < dist[nx][ny][dir]) {
                dist[nx][ny][dir] = cost;
                pq.offer(new Node(nx, ny, dir, cost));
            }

            
            if (map[nx][ny] == '!') {
              
                for (int nd = 0; nd < 4; ++nd) {
                    if (nd == dir) continue; 
                 
                    if ((dir == 0 && nd == 1) || (dir == 1 && nd == 0) ||
                        (dir == 2 && nd == 3) || (dir == 3 && nd == 2)) {
                        continue;
                    }
                    int nCost = cost + 1;
                    if (nCost < dist[nx][ny][nd]) {
                        dist[nx][ny][nd] = nCost;
                        pq.offer(new Node(nx, ny, nd, nCost));
                    }
                }
            }
        }

        int answer = INF;
        for (int d = 0; d < 4; ++d) {
            answer = Math.min(answer, dist[ex][ey][d]);
        }
        System.out.println(answer);
    }
}