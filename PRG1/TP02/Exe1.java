package fr.istic.prg1.tp02;

import java.util.Scanner;

public class Exe1 {
    // Affichage de la plus grande valeur de deux entiers

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Entrez a : ");
        int a = scan.nextInt();

        System.out.print("Entrez b : ");
        int b = scan.nextInt();

        if (a > b) {
            System.out.printf("La plus grande valeur est: %d\n", a);
        }
        if (a < b) {
            System.out.printf("La plus grande valeur est: %d\n", b);
        }
        if (a == b) {
            System.out.println("Il n'y a pas de plus grande valeur (a == b)");
        }

        scan.close();
    }
}
