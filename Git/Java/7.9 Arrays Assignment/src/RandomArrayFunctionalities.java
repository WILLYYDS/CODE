import java.util.Scanner;
class RandomArrayFunctionalities
{
    /** method isSubset
 * @param arr1, array1
 * @param arr2, array2
 */
    int count;
    public boolean isSubset = false;
    public boolean isSubset(int array1[],int array2[]){
        //used loops here to find out substring
        for(int i=0;i<array2.length;i++){
            for(int j=0;j<array1.length;j++){
                if(array2[i]==array1[j]){
                    count++;
                    continue;
                }
            }
        }
        if(count==array2.length)
            return true;
        else
            return false;
    }
    /** method printString
     * @param str, denoting string
     * @param num, denoting number
     */
    void printString(String str,int num){

        for(int i=num;i>0;i--){
            for(int j=0;j<i;j++){
                System.out.print(str.charAt(j));
            }
        }
    }
}