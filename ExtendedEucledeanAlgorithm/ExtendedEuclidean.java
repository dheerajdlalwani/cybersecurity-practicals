import java.util.*;

public class ExtendedEuclidean {
    static int GCD(int num1, int num2) {
        if (num2 == 0)
            return num1;
        return GCD(num2, num1 % num2);
    }

    static int multiplicativeInverse(int num1, int num2, int t1, int t2) {
        if (num2 == 0)
            return t1;
        int t = t1 - (t2 * num1 / num2);
        return multiplicativeInverse(num2, num1 % num2, t2, t);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num1 = sc.nextInt();
        int num2 = sc.nextInt();
        int gcd = ExtendedEuclidean.GCD(num1, num2);
        System.out.println("GCD: " + gcd);
        if (gcd == 1) {
            if (num1 < num2)
                System.out.println("Multiplicative Inverse: " + ExtendedEuclidean.multiplicativeInverse(num2, num1, 0, 1));
            else
                System.out.println("Multiplicative Inverse: " + ExtendedEuclidean.multiplicativeInverse(num1, num2, 0, 1));
        }
        sc.close();
    }
}