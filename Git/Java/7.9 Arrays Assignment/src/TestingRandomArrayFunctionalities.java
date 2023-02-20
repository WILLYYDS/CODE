import java.util.Scanner;

class TestingRandomArrayFunctionalities{
    public static void main(String args[])
    {
        //initialized all required variables
        String str;
        int length,number_str;
        System.out.println("Enter Length of the first array ");
        //scanner object
        Scanner sc=new Scanner(System.in);
        length=sc.nextInt();

        int array1[]=new int[length];
        System.out.println("Enter the first array elements");
        for(int i=0;i<length;i++){
            array1[i]=sc.nextInt();
        }

        //code for second array input
        System.out.println("Enter Length of the second array ");
        length=sc.nextInt();
        int array2[]=new int[length];
        System.out.println("Enter the second array elements");
        for(int i=0;i<length;i++){
            array2[i]=sc.nextInt();
        }

        //created object and called methods
        RandomArrayFunctionalities object=new RandomArrayFunctionalities();

        if(object. isSubset(array1, array2)){
            System.out.println("Array2 is subset of array 1");
        }
        else{
            System.out.println("Array 2 is not subset of array 1");
        }
        System.out.println("Enter a String :");
        str=sc.next();
        System.out.println("Enter a Number ");
        number_str=sc.nextInt();
        object.printString(str,number_str);
        sc.close();
    }
}