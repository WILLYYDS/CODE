public class RandomFunctionalities
{

/**
 *method for PutTogether
 */

    public String putTogether(String firstWord, String secondWord)
    {
        int a = firstWord.length();
        int b = secondWord.length();

/**
 * get the length of first and second word
 * consider the situation of empty string
 */
     if (a == 0)
     {
         return secondWord;
     }
     else if( b == 0)
     {
         return  firstWord;
     }
/**
 * consider last digit of the first word same as the first digit of the second word.
 */

    if (firstWord.charAt(a-1) == secondWord.charAt(0))
    {
        return firstWord.substring(0, a - 1) + secondWord;
    }
    else
    {
        return firstWord + secondWord;
    }
    }


    /**
     *method for SwapThree
     */
    public static String swapThree(String word) {
        int a = word.length();
/**
 * get length of word
 * consider when length=1 and 2
 * consider when length >=3
 */
        if (a == 1) {
            return word;
        } else if (a == 2) {
            return "" + word.charAt(1) + word.charAt(0);
        } else if (a >= 3) {
            return word.substring(0, a - 3) + word.charAt(a - 1) + word.charAt(a - 2) + word.charAt(a - 3);
        }
        return word;

    }


    /**
     * method of overEleven
     */
    public static boolean overEleven(int first, int second, int third)
    {
        int a = first;
        int b = second;
        int c = third;
/**
 * get three number
 * consider any one of the three integers is greater than the sum of the other two by 11 or more
 */
     if (b+c <= a-11 || c+a <= b-11 || a+b <= c-11)
     {
         return true;
     }
     else
     {
         return false;
     }
    }


  /**
  * method of isOdd
  */
 public static boolean isOdd(int number)
 {
     int a = number;

/**
 * get number
 * Divide by 2 to determine odd and even numbers
 */
     if (a%2 == 1)
      {
          return true;
      }
      else if (a == 0)
      {
          return true;
      }
      else
     {
         return false;
     }

  }


    /**
     *method of  isEven
     */
    public static boolean isEven(int number)
    {
        if (number%2 == 1)
        {
            return false;
        }
        else if (number == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }


    /**
     *method of twentyOne
     */

    public static int twentyOne(int firstNumber, int secondNumber)
    {
        if (firstNumber == secondNumber)
        {
            return -1;
        }
        if(java.lang.Math.abs(firstNumber - 21) < java.lang.Math.abs(secondNumber - 21))
        {
            return firstNumber;
        }
       else
        {
            return secondNumber;
        }
    }

}
