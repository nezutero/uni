package fr.istic.prg1.tp03;

public class Exe2 {
    // Conversion degrés Fahrenheit vers Celsius

    public static void main(String[] args) {
        double fahr = -20.0;
        double celsius = 0.0;

        for (int i = 0; i < 27; i++) {
            celsius = fahr * (5.0 / 9.0) - (160.0 / 9.0);
            System.out.printf("%.0f degres F ---> %.8f degres C\n", fahr, celsius);
            fahr += 10;
        }
    }
}
