public class Exe2 {

    /** Prints row `row` (1 <= row <= maxScore) of the target. */
    public static void printRow(int row, int maxScore) {
        int width = 2 * maxScore - 1;                 // seats in every row
        int plateauValue = row;                       // row r has a plateau of r's
        int stairLength = plateauValue - 1;           // stair climbs 1, 2, ..., plateauValue - 1
        int plateauLength = width - 2 * stairLength;  // seats left after both stairs

        printAscending(1, stairLength);               // left stair
        printRepeated(plateauValue, plateauLength);   // plateau
        printDescending(stairLength, 1);              // right stair
        System.out.println();
    }

    public static void printTarget(int maxScore) {
        for (int row = 1; row <= maxScore; row++) {       // top half + middle row
            printRow(row, maxScore);
        }
        for (int row = maxScore - 1; row >= 1; row--) {   // bottom half, mirrored
            printRow(row, maxScore);
        }
    }

    /** Prints from, from+1, ..., to. Prints nothing if from > to. */
    public static void printAscending(int from, int to) {
        for (int value = from; value <= to; value++) {
            System.out.print(value + " ");
        }
    }

    /** Prints `value` exactly `count` times. */
    public static void printRepeated(int value, int count) {
        for (int printed = 1; printed <= count; printed++) {
            System.out.print(value + " ");
        }
    }

    /** Prints from, from-1, ..., to. Prints nothing if from < to. */
    public static void printDescending(int from, int to) {
        for (int value = from; value >= to; value--) {
            System.out.print(value + " ");
        }
    }

    public static void main(String[] args) {
        printTarget(4);
    }
}
