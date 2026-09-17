package fr.istic.prg1.tp04;

public class Exe1 {

    public static void main(String[] args) {
        int nbCol = 10;
        int nbLig = 4;
        for (int i = 0; i < nbLig; i++) {
            for (int j = 0; j < nbCol; j++) {
                System.out.print(".");
            }
            System.out.println();
        }
    }
}
