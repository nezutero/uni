import java.util.Scanner; // pour utiliser un scanner

public class Exe3 {
    // Saisie de valeurs au clavier

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Entrez un nombre entier :");
        int nombre = scan.nextInt();
        System.out.println("Le double de votre nombre est :");
        System.out.println(nombre * 2);
        scan.close();
    }
}
