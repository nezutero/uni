public class Exe3 {
    public static void main(String[] args) {
        int a = 2;
        int b = 3;
        int c = 3;
        int produit = 0; // 0 -> i = 1, j++ * 3 -> 9 -> i=2, j++ * 3 -> 18
        
        for (int i = 1; i <= a; i++) { // 18 = 3+3) + (3+3+3)
            for (int j = 1; j <= b; j++) {
                produit = produit + c;
            }
        }

        System.out.println(a + " x " + b + " x " + c + " = " + produit);
    }
}
