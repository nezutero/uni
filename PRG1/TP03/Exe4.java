package fr.istic.prg1.tp03;

import java.util.Random;
import java.util.Scanner;

public class Exe4 {
	// Deviner le nombre

	/*
	 * Un générateur aléatoire
	 */
	public static final Random rand = new Random();

	/**
	 * Retourne un entier aléatoire entre a (inclus) et b (inclus)
	 * 
	 * @param a un entier positif
	 * @param b un entier positif
	 * @return Un entier aléatoire entre a (inclus) et b (inclus)
	 */
	public static int entierAleatoire(int a, int b) {
		return rand.nextInt(a, b + 1);
	}

	public static void main(String[] args) {

	}
}
