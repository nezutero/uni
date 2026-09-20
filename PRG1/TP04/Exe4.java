public class Exe4 {
    public static void main(String[] args) {
        int b = 2; // base
        int t = 1; // b^0 = 1 — the multiplicative identity, nothing multiplied yet
        int exp = 3; // exponent

        for (int i = 1; i <= exp; i++) {
            int produit = 0; // fresh accumulator, reset EVERY outer (i) pass/iteration
            for (int j = 1; j <= b; j++) {
                produit = produit + t; // a * a * a * ... * an
            }
            t = produit; // this (i) iteration/pass's multiplication is done; t is updated
        }
        System.out.printf("%d^%d = %d\n", b, exp, t);
    }
}
