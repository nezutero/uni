package fr.istic.prg1.tp01;

// (Variable non declaree) :
// Exe2.java:23: error: cannot find symbol

// (Variable declaree non initialisee) :
// Exe2.java:26: error: variable maQuatriemeVariable might not have been initialized

// (Erreur de type lors de l’affectation) :
// Exe2.java:28: error: variable maQuatriemeVariable might not have been initialized

// (Erreur de type lors de l’utilisation) : 
// Exe2.java:37: error: incompatible types: possible lossy conversion from double to int

public class Exe2 {
	// Variables : déclaration, initialisation, utilisation et (ré)affectation

	public static void main(String[] args) {
        int maVariable;
        maVariable = 23;
        System.out.println(maVariable);

        maVariable = 5;
        System.out.println(maVariable);

        double monAutreVariable = 42.7;
        System.out.println(monAutreVariable);

        boolean maTroisiemeVariable = true;
        System.out.println(maTroisiemeVariable);

        int maQuatriemeVariable;
        System.out.println(maQuatriemeVariable);

        monAutreVariable = 12;
        System.out.println(monAutreVariable);
        maVariable = 31.59;
        System.out.println(monAutreVariable);
	}
}
