public class TestingRandomFunctionalities2 {


    public static void main(String[] args) {
        RandomFunctionalities2 r = new RandomFunctionalities2();

        System.out.println(r.mixWords("hat", "cat") + " " + r.mixWords("settle", "down") + " " +
                r.mixWords("double", "double")
                + " " + r.mixWords("getting", ""));
        System.out.println(r.switcheroo("william") + " " + r.switcheroo("me") + " "
                + r.switcheroo("green") + " " + r.switcheroo("mickey") + " "
                + r.switcheroo("john") + " " + r.switcheroo("go") + " "
                + r.switcheroo("h") + " " + r.switcheroo(""));
        System.out.println(r.longestSet("ahhhhhhhhssssdahsssh") + " " + r.longestSet("ss") + " "
                +
                r.longestSet("sss") + " " + r.longestSet("ssss") + " " +
                r.longestSet("will"));


    }
}