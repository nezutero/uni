import java.util.Scanner;

public class Exe5 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the height (h >= 1) : ");
        int height = scan.nextInt();

        System.out.println();

        if (height >= 1) {
            int size = height;
            // first figure
            for (int i = size; i >= 1; i--) { // columns |
                for (int j = size; j >= 1; j--) { // rows .....
                    System.out.print("*");
                }
                System.out.println();
                size--;
            }

            size = height;
            System.out.println("-------------------------");

            // second figure
            for (int i = 1; i <= size; i++) { // columns |
                for (int j = 1; j <= size; j++) { // rows .....
                    if (i == 1 || i == size || j == 1 || j == size) {
                        System.out.print("*");
                    } else {
                        System.out.print(" ");
                    }
                }
                System.out.println();
            }

            size = height;
            System.out.println("-------------------------");

            // third figure
            for (int i = 1; i <= size; i++) {
                for (int j = 1; j <= size; j++) {
                    if (i == 1 || i == size) {
                        System.out.print("*");
                    } else if (j == size - (i - 1)) {
                        System.out.print("*");
                    } else {
                        System.out.print(" ");
                    }
                }
                System.out.println();
            }

            size = height;
            System.out.println("-------------------------");

            // forth figure
            for (int i = 1; i <= height; i++) {
                int width = 2 * height - 1;
                int stars = 2 * i - 1;
                int spaces = (width - stars) / 2;

                for (int j = 1; j <= width; j++) {
                    if (j > spaces && j <= spaces + stars) {
                        System.out.print("*");
                    } else {
                        System.out.print(" ");
                    }
                }
                System.out.println();
            }

            System.out.println("-------------------------");

            // additional figure done by accident
            for (int i = 1; i <= size; i++) {
                for (int j = 1; j <= (2 * i) - 1; j++) {
                    if (((2 * i) - 1) % 2 == 1) {
                        System.out.print("*");
                    } else {
                        System.out.print(" ");
                    }
                }
                System.out.println();
            }

            size = height;
            System.out.println("-------------------------");

            // fifth figure
            for (int i = 1; i <= size; i++) {
                for (int j = 1; j <= size; j++) {
                    if (j == 1 || j == size) {
                        System.out.print("*");
                    } else if (j == i) {
                        System.out.print("*");
                    } else {
                        System.out.print(" ");
                    }
                }
                System.out.println();
            }

            size = height;
            System.out.println();

        } else {
            System.out.println("[ERROR] The value has to be greater or equal to 1 !");
        }

        scan.close();
    }
}
