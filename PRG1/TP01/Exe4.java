package fr.istic.prg1.tp01;

import java.util.Scanner;

// Importer ici les bibliothèques nécessaires aux scanners

public class Exe4 {
    // Operations de base sur les nombres entiers, à virgule, et les booleens

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Entrez a : ");
        int a = scanner.nextInt();

        System.out.print("Entrez b : ");
        int b = scanner.nextInt();

        System.out.println("a = " + a);
        System.out.println("b = " + b);

        int temp = a;
        a = b;
        b = temp;

        System.out.println("Après échange :");
        System.out.println("a = " + a);
        System.out.println("b = " + b);

        System.out.println("Double de a = " + (2 * a));
        System.out.println("Moitié de b = " + (b / 2.0));

        System.out.println("Quotient = " + (a / b));
        System.out.println("Reste = " + (a % b));

        System.out.println("a < b : " + (a < b));
        System.out.println("a >= b : " + (a >= b));

        double c = scanner.nextDouble();
        double d = scanner.nextDouble();

        System.out.println("Somme : " + (c + d));
        System.out.println("Difference : " + (c - d));
        System.out.println("Difference : " + (c * d));
        System.out.println("a < c : " + (a < c));
        System.out.println("a >= c : " + (a >= c));

        boolean e = scanner.nextBoolean();
        boolean f = scanner.nextBoolean();

        System.out.println("e = " + e);
        System.out.println("!e : " + (!e));
        System.out.println("e && f : " + (e && f));
        System.out.println("e || f : " + (e || f));

        scanner.close();
    }
}
