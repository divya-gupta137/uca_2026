import java.util.Set;
import java.util.HashSet;

class set_matrix_zeroes_q19 {
    public void setZeroes(int[][] matrix) {
        Set<Integer> zerorows = new HashSet<>();
        Set<Integer> zerocols = new HashSet<>();

        int n = matrix.length;
        int m = matrix[0].length;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    zerorows.add(i);
                    zerocols.add(j);
                }
            }
        }

        for(int rows: zerorows){
            for(int j=0; j<m; j++){
                matrix[rows][j]=0;
            }
        }

        for(int cols: zerocols){
            for(int j=0; j<n; j++){
                matrix[j][cols] = 0;
            }
        }
    }

    public static void main(String[] args) {

        int[][] matrix = {
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1}
        };

        set_matrix_zeroes_q19 obj = new set_matrix_zeroes_q19();

        obj.setZeroes(matrix);

        System.out.println("Result:");

        for (int i = 0; i < matrix.length; i++) {

            for (int j = 0; j < matrix[0].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }

            System.out.println();
        }
    }
}