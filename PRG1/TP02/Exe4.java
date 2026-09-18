import java.util.Scanner;

public class Exe4 {
    // Affichage dans l'ordre croissant

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Entrez a : ");
        int a = scan.nextInt();

        System.out.print("Entrez b : ");
        int b = scan.nextInt();

        System.out.print("Entrez c : ");
        int c = scan.nextInt();

        int tmp;

        if (a > b) {
            tmp = a;
            a = b;
            b = tmp;
        }

        if (a > c) {
            tmp = a;
            a = c;
            c = tmp;
        }

        if (b > c) {
            tmp = b;
            b = c;
            c = tmp;
        }

        if (a == b && a == c) {
            System.out.printf("%d == %d == %d\n", a, b, c);
        } else {
            System.out.printf("%d <= %d <= %d\n", a, b, c);
        }

        scan.close();
    }
}
