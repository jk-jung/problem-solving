import java.lang.*;


public class Tour {
    public static int tour(int[] A, int K) {
        int n = A.length;
        int best = 0;
        int count = 1;
        for (int i = 0; i < n - K - 1; i++) {
            if(A[i] == A[i + 1])
                count = count + 1;
            else
                count = 1;    // 수정 1
            if (count > best)
                best = count;
        }
        int result = Math.max(1, best + K); // 수정 2

        return result;
    }
}