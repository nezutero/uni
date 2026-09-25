public class Exe2 {
    // Q1 : Écrire une fonction impotMontant qui prend en entrée le salaire d'une
    // personne et qui retourne le montant de son impôt.
    public static double impotMontant(double salaire) {
        double impot = 0;

        if (salaire > 10064) {
            impot += (Math.min(salaire, 25659) - 10064) * 0.11;
        }

        if (salaire > 25659) {
            impot += (Math.min(salaire, 73369) - 25659) * 0.30;
        }

        if (salaire > 73369) {
            impot += (Math.min(salaire, 157805) - 73369) * 0.41;
        }

        if (salaire > 157805) {
            impot += (salaire - 157805) * 0.45;
        }

        return impot;
    }

    // Q2: Écrire une fonction pourcentageImposition, qui prend en entrée le salaire
    // d'une personne et qui retourne son pourcentage d'imposition.

    public static double pourcentageImposition(double salaire) {
        double pourcentage = (impotMontant(salaire) / salaire) * 100;

        return pourcentage;
    }

    // Q3 : Écrire la fonction gainMariage pour calculer le gain d'impot des couples
    public static double gainMariage(double salaire1, double salaire2) {
        double moyenne = (salaire1 + salaire2) / 2;
        double impotMontantCouple = impotMontant(moyenne) * 2;
        double impotMontantCelibataires = impotMontant(salaire1) + impotMontant(salaire2);
        double gain = impotMontantCelibataires - impotMontantCouple;

        return gain;
    }

    public static void main(String[] args) {
        System.out.println(impotMontant(30000));
        System.out.println(pourcentageImposition(30000));
        System.out.println(gainMariage(10000, 15000));
    }
}
