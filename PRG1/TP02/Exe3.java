import java.util.Scanner;

public class Exe3 {
    // Annee bissextile

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Annee : ");
        int annee = scan.nextInt();

        if (annee % 4 == 0 && annee % 100 != 0 || annee % 400 == 0) {
            System.out.printf("L’annee %d est bissextile !\n", annee);
        } else {
            System.out.printf("L’annee %d n'est pas bissextile !\n", annee);
        }

        scan.close();
    }
}
