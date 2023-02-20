public class testingRandomFunctionalities {

    public static void main(String[] args)
        {

            RandomFunctionalities test = new RandomFunctionalities();

            System.out.println(test.putTogether("set", "yes"));
            System.out.println(test.putTogether("old", "day"));
            System.out.println();


            System.out.println(test.swapThree("william"));
            System.out.println(test.swapThree("happy"));
            System.out.println(test.swapThree("to"));
            System.out.println(test.swapThree("asdasd"));
            System.out.println();

            System.out.println(test.overEleven(3, 2, 55));
            System.out.println(test.overEleven(3, 2, 3));
            System.out.println(test.overEleven(13, 0, 4));
            System.out.println();

            System.out.println(test.isOdd(313));
            System.out.println(test.isOdd(0));
            System.out.println(test.isOdd(234));
            System.out.println();

            System.out.println(test.isEven(453));
            System.out.println(test.isEven(0));
            System.out.println(test.isEven(22));
            System.out.println();

            System.out.println(test.twentyOne(14, 19));
            System.out.println(test.twentyOne(12, 21));
            System.out.println(test.twentyOne(21, 21));

        }

    }
