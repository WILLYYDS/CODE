public class RandomFunctionalities2
{
    /**
     * method of mixWords
     * @param firstWord
     * @param secondWord
     * @return
     */
    public static String mixWords(String firstWord, String secondWord){

        if(firstWord.length() == 0)
        {
            return secondWord;
        }

        if(secondWord.length() == 0)
        {
            return firstWord;
        }


        String temp="";

/**
 *Comparing the length of the first word with that of the second word
 */
        if(firstWord.length() <= secondWord.length())
        {
            for(int i=0; i< firstWord.length(); i++)
            {
                temp = temp + firstWord.charAt(i) + secondWord.charAt(i);
            }

            return temp + secondWord.substring(firstWord.length());
        }
        else
        {
            for(int i=0; i< secondWord.length(); i++)
            {
                temp = temp + firstWord.charAt(i) + secondWord.charAt(i);
            }
            return temp + firstWord.substring(secondWord.length());
        }
    }

    /**
     * method of switcheroo
     * @param word
     * @return
     */
    public static String switcheroo(String word)
    {
        /**
         * Classification discussion length of word less than 3
         */

        if(word.length()<3)
        {
            return word;
        }
        else if(word.length()==3)
        {
            return ""+word.charAt(1)+word.charAt(2)+word.charAt(0);
        }
        else
        {
            String newWord ="";
            /**
             * when the length is more than 3
             */
            int rounds =word.length()/3;

            for(int i=0; i<rounds; i++)
            {
                String temp;
                temp= word.substring(3*i,3*i+3);
                newWord =newWord+ temp.charAt(1)+temp.charAt(2)+temp.charAt(0);
            }
            return newWord+word.substring(3*rounds-1);
        }
    }

    /**
     * method of the longestSet
     * @param word
     * @return
     */
    public static String longestSet(String word )
    {
        // using a boolean to control return
        boolean equal = false;
        String temp="";

        for(int i=0;i< word.length()-1;i++)
        {
            if(word.charAt(i) == word.charAt(i+1))
            {
                equal = true;
            }
            else
            {
                temp = temp + word.charAt(i);
            }
        }

        temp = temp + word.charAt(word.length()-1);

        if(equal == false)
        {
            return "";
        }
        else
        {
            return temp;
        }
    }

}