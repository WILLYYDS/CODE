public class TestingRandomFunctionalities3 {
    public static void main(String[] args) {

        int summing1 = RandomFunctionalities3.summing(2123);
        int summing2 = RandomFunctionalities3.summing(34146);
        int summing3 = RandomFunctionalities3.summing(444);
        int summing4 = RandomFunctionalities3.summing(7220);
        int summing5 = RandomFunctionalities3.summing(1124);
        System.out.println("summing1 = " + summing1);
        System.out.println("summing2 = " + summing2);
        System.out.println("summing3 = " + summing3);
        System.out.println("summing4 = " + summing4);
        System.out.println("summing5 = " + summing5);


        int i1 = RandomFunctionalities3.count9(123);
        int i2 = RandomFunctionalities3.count9(12239);
        int i3 = RandomFunctionalities3.count9(996);
        int i4 = RandomFunctionalities3.count9(1399);
        int i5 = RandomFunctionalities3.count9(999909);
        System.out.println("i1 = " + i1);
        System.out.println("i2 = " + i2);
        System.out.println("i3 = " + i3);
        System.out.println("i4 = " + i4);
        System.out.println("i5 = " + i5);


        String newStr1 = RandomFunctionalities3.noDupsTogether("aaa");
        String newStr2 = RandomFunctionalities3.noDupsTogether("adsacccccccccccccfabc");
        String newStr3 = RandomFunctionalities3.noDupsTogether("dsadsssyyyyqtx");
        String newStr4 = RandomFunctionalities3.noDupsTogether("abadadrrggggASA");
        String newStr5 = RandomFunctionalities3.noDupsTogether("wadadvbbagff");
        System.out.println("s1 = " + newStr1);
        System.out.println("s2 = " + newStr2);
        System.out.println("s3 = " + newStr3);
        System.out.println("s4 = " + newStr4);
        System.out.println("s5 = " + newStr5);


    }
}