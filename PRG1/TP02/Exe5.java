package fr.istic.prg1.tp02;

import java.util.Scanner;

public class Exe5 {
    // Conversion secondes

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        System.out.print("Entrez un nombre entier de secondes : ");
        int totalSeconds = scan.nextInt();

        int days = totalSeconds / 86400;
        int remainingSecondsAfterDays = totalSeconds % 86400;

        int hours = remainingSecondsAfterDays / 3600;
        int remainingSecondsAfterHours = remainingSecondsAfterDays % 3600;

        int minutes = remainingSecondsAfterHours / 60;
        int remainingSeconds = remainingSecondsAfterHours % 60;

        if (totalSeconds > 0) {
            System.out.printf("Cela donne %d jours %d heures %d minutes %d secondes\n",
                    days, hours, minutes, remainingSeconds);
        } else {
            System.out.printf("Number has to be greater than %d, try again.\n", totalSeconds);
        }

        scan.close();
    }
}
