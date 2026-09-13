package fr.istic.prg1.tp02;

import java.util.Scanner;

public class Exe2 {
    // Parite d'une somme de trois entiers

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Entrez a : ");
        int a = scan.nextInt();

        System.out.print("Entrez b : ");
        int b = scan.nextInt();
        
        System.out.print("Entrez c : ");
        int c = scan.nextInt();

        int somme = a + b + c;

        if (somme % 2 == 0) {
            System.out.println("La somme des trois entiers est paire.");
        } else {
            System.out.println("La somme des trois entiers est impaire.");
        }

        scan.close();
    }
}
