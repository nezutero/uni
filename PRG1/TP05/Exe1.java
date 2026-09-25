public class Exe1 {
    public static void enumereCroissante(int vMin, int vMax) {
        if (!(vMin <= vMax)) {
            System.err.println("Error: vMin has to be smaller than vMax");
            return;
        }

        for (int i = vMin; i <= vMax; i++) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    public static void enumereDecroissante(int vMax, int vMin) {
        if (!(vMax >= vMin)) {
            System.err.println("Error: vMax has to be bigger than vMin");
            return;
        }

        for (int i = vMax; i >= vMin; i--) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    public static void enumere(int deb, int fin) {
        if (deb < fin) {
            enumereCroissante(deb, fin);
        } else {
            enumereDecroissante(deb, fin);
        }
    }

    public static void main(String[] args) {
        enumere(1, 10);
    }
}
