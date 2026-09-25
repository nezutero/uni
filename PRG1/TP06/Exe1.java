public class Exe1 {

    public static int valeurAbsolue(int a) {
        if (a < 0) {
            return a * -1;
        }
        return a;
    }

    public static int minimum(int a, int b) {
        if (a < b) {
            return a;
        }
        return b;
    }

    public static int maximum(int a, int b) {
        if (a < b) {
            return b;
        }
        return a;
    }

    public static boolean estInferieurStrictA(int a, int b) {
        if (a < b) {
            return true;
        }
        return false;
    }

    public static boolean estInferieurOuEgalA(int a, int b) {
        if (a <= b) {
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println(valeurAbsolue(-10));
        System.out.println(minimum(5, 1));
        System.out.println(maximum(10, 1));
        System.out.println(estInferieurStrictA(5, 1));
        System.out.println(estInferieurOuEgalA(5, 5));
    }
}
