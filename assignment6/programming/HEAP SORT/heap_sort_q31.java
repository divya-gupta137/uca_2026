import java.util.Random;

class heap_sort_q31 {

    public static void heapifydown(int[] arr, int i, int n){

        int left = 2*i+1;
        int right = 2*i+2;
        int size = n;
        int max = i;
        if(left<size && arr[left] > arr[max]){
            max =left;
        }
        if(right<size &&arr[right] > arr[max]){
            max= right;
        }
        
        if(max!=i){
            int temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
            heapifydown(arr,max, n);
        }
    }
    
    public static void buildmaxheap(int[] arr){
        int n = arr.length;
        for(int i=n/2-1; i>=0; i--){
            heapifydown(arr,i,n);
        }
    }
    
    public static void sort(int[] arr, int n ){
        for(int i=n-1; i>0; i--){
            int temp =arr[0];
            arr[0]= arr[i];
            arr[i] = temp;
            n--;
            heapifydown(arr,0, n);
        }
        
    }
    
    public static void heapSort(int arr[]) {
        buildmaxheap(arr);
        sort(arr, arr.length);
    }

    public static int[] randomarray(int n){
        Random random = new Random();
        int[] arr = new int[n];
        for(int i=0;i<n; i++){
            arr[i]= random.nextInt(n);
        }
        return arr;
    }

    public static int[] ascendingArray(int n) {
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        return arr;
    }

    public static int[] descendingArray(int n) {
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = n - i;
        }
        return arr;
    }


    public static long measureTime(int[] arr){
        long start =System.nanoTime();
        heapSort(arr);
        long end = System.nanoTime();

        return end - start;
    }


    public static boolean isSorted(int[] arr) {

        for (int i = 1; i < arr.length; i++) {
            if (arr[i - 1] > arr[i]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args){
        int[] sizes = {1000, 5000, 10000, 50000, 100000};
        for(int n : sizes){
            int[] random = randomarray(n);
            int[] ascending = ascendingArray(n);
            int[] descending = descendingArray(n);

            long randomtime = measureTime(random);
            long ascendingtime = measureTime(ascending);
            long descendingtime = measureTime(descending);

            if (!isSorted(random) ||
                !isSorted(ascending) ||
                !isSorted(descending)) {

                System.out.println("Sorting failed!");
                return;
            }

             System.out.println(
                n + "\t" +
                randomtime / 1_000_000.0 + " ms\t" +
                ascendingtime / 1_000_000.0 + " ms\t" +
                descendingtime / 1_000_000.0 + " ms"
            );
        }
    }
}