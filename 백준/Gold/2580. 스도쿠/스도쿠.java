import java.io.*;
import java.util.*;

public class Main {

    static int[][] board = new int[9][9];
    static boolean[][] row = new boolean[9][10]; 
    static boolean[][] col = new boolean[9][10];
    static boolean[][] box = new boolean[9][10]; 
    static List<int[]> blanks = new ArrayList<>();
    static boolean solved = false;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int r = 0; r < 9; r++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int c = 0; c < 9; c++) {
                int x = Integer.parseInt(st.nextToken());
                board[r][c] = x;
                if (x == 0) {
                    blanks.add(new int[]{r, c});
                } else {
                    row[r][x] = true;
                    col[c][x] = true;
                    box[boxIndex(r, c)][x] = true;
                }
            }
        }

        dfs(0);

    }

    static int boxIndex(int r, int c) {
        return (r / 3) * 3 + (c / 3);
    }

    static void dfs(int idx) {
        if (solved) return; 

        if (idx == blanks.size()) {
            solved = true;
            printBoard();
            return;
        }

        int[] pos = blanks.get(idx);
        int r = pos[0];
        int c = pos[1];
        int b = boxIndex(r, c);

        for (int num = 1; num <= 9; num++) {
            if (row[r][num] || col[c][num] || box[b][num]) continue;

            board[r][c] = num;
            row[r][num] = col[c][num] = box[b][num] = true;

            dfs(idx + 1);
            if (solved) return;

            board[r][c] = 0;
            row[r][num] = col[c][num] = box[b][num] = false;
        }
    }

    static void printBoard() {
        StringBuilder sb = new StringBuilder();
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                sb.append(board[r][c]);
                if (c < 8) sb.append(' ');
            }
            sb.append('\n');
        }
        System.out.print(sb.toString());
    }
}