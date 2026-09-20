import java.util.Random;
import java.util.Scanner;

public class Exe4 {
    // Deviner le nombre

    /*
     * Un générateur aléatoire
     */
    public static final Random rand = new Random();

    /**
     * Retourne un entier aléatoire entre a (inclus) et b (inclus)
     * 
     * @param a un entier positif
     * @param b un entier positif
     * @return Un entier aléatoire entre a (inclus) et b (inclus)
     */
    public static int entierAleatoire(int a, int b) {
        return rand.nextInt(a, b + 1);
    }

    public static void main(String[] args) {
        int r = entierAleatoire(1, 100);

        Scanner scan = new Scanner(System.in);
        int n;

        do {
            System.out.print("Deviner le nombre (1-100) : ");
            n = scan.nextInt();
            if (n < r) {
                System.out.println("Trop petit !");
            } else if (n > r) {
                System.out.println("Trop grand !");
            } else {
                System.out.println("Gagné !");
            }
        } while (n != r);

        scan.close();
    }
}
