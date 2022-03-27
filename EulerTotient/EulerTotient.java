import java.security.DrbgParameters.Reseed;

public class EulerTotient {
    static int gcd (int x, int y)
    {
        if(x == 0) {
            return y;
        }
        else {
            return gcd(y % x, x);
        }
    }

    static int phi(int n) {
        int result = 1; 
        for (int i = 2; i < n; i++) {
            if(gcd(i, n) == 1) {
                result++;
            }
        }
        return result;
    }
    public static void main(String [] args)
    {
        int n;

        for(n = 1; n < 12; n++) {
            System.out.println("Phi(" + n +") = " + phi(n));
        }
    }
}