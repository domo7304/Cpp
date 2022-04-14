class ArrayUtil {
    public static int[] concat(int[] arr1, int[] arr2){
        int tmp[] = new int[arr1.length + arr2.length];
        System.arraycopy(arr1, 0, tmp, 0, arr1.length);
        System.arraycopy(arr2, 0, tmp, arr1.length, arr2.length);
        return tmp;
    }

    public static void print(int[] arr){
        System.out.print("[");
        for (int i = 0; i < arr.length; i++) System.out.print(arr[i] + " ");
        System.out.println("]");
    }
}

public class StaticEx{
    public static void main(String[] args) {
        int[] array1 = {1, 5, 7, 9};
        int[] array2 = {3, 6, -1, 100, 77};
        int[] array3 = ArrayUtil.concat(array1, array2);
        ArrayUtil.print(array3);
    }
}
