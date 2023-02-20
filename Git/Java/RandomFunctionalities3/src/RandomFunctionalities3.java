public class RandomFunctionalities3
{
    /**
    using recursion with no loops
    */
    public static int summing(int num)
    {
        if (num == 0) {
            return 0;
        }
        else {
            return ( num % 10 + summing(num/10));

        }
    }

    /**
     *start with the ones place and see if there's a 9
     */
    public static int count9(int num)
    {
        int count = 0;
        if (num == 0) {
            return 0;
        }
        else {
            int t = num % 10;
            if (t == 9)count++;
            count = count + (count9(num/10));
            return count;
        }
    }

    /**
     * Newstr is created to store each character
     * characters are repeated before and after comparison
     * To determine how to store new characters.
     */
    public static  String noDupsTogether(String word ){
        if (word.length() <= 1)
            return word;
        else {
            String first = word.substring(0,1);

            String second = word.substring(1,2);

            if (!first.equals(second))
                return first + noDupsTogether(word.substring(1));
            else
                return  noDupsTogether(word.substring(1));
        }
    }
}
