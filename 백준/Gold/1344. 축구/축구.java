import java.util.*;

public class Main {
    static boolean[] isPrime = new boolean[19];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double pA = sc.nextInt() / 100.0;
        double pB = sc.nextInt() / 100.0;

        initPrimes();

        double[][] dpA = new double[19][19];
        double[][] dpB = new double[19][19];

        dpA[0][0] = 1.0;
        dpB[0][0] = 1.0;

        for (int i = 1; i <= 18; i++) {
            for (int j = 0; j <= 18; j++) {
   
                dpA[i][j] += dpA[i - 1][j] * (1 - pA);
              
                if (j > 0) dpA[i][j] += dpA[i - 1][j - 1] * pA;

       
                dpB[i][j] += dpB[i - 1][j] * (1 - pB);
              
                if (j > 0) dpB[i][j] += dpB[i - 1][j - 1] * pB;
            }
        }


        double noPrimeA = 0.0;

        double noPrimeB = 0.0;

        for (int j = 0; j <= 18; j++) {
            if (!isPrime[j]) noPrimeA += dpA[18][j];
            if (!isPrime[j]) noPrimeB += dpB[18][j];
        }

        double answer = 1 - (noPrimeA * noPrimeB);

        System.out.println(answer);
    }

    static void initPrimes() {
        for (int i = 2; i <= 18; i++) {
            isPrime[i] = isPrimeNumber(i);
        }
    }

    static boolean isPrimeNumber(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }
}