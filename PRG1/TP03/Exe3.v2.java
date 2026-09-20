import java.util.Scanner;

public class Exe3 {
    // Somme de 1 à n

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Entrez un nombre : ");
        int n = scan.nextInt();
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
            if (i == n) {
                System.out.printf("= %d", sum);
            } else {
                System.out.print(i + " + ");
            }
        }
        System.out.println();
        scan.close();
    }
}

