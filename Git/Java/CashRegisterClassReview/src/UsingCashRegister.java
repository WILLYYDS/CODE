public class UsingCashRegister
{
    public static void main (String [ ] args)
    {
        CashRegister A = new CashRegister();
        {
            /**
             customer A
             */
            // "A" is a new customer
            A.addItem(23.5);
            //"A" add 1 Item
            A.addItem(32.5);
            //"A" add 2 Item
            A.addItem(14);
            //"A" add 3 Item
            A.removeItem(14);
            //"A" remove 1Item
            System.out.println("The number of item is: ");
            System.out.println(A.getItemCount());
            //"A" get ItemCount
            System.out.println("Total of the price is: ");
            System.out.println(A.getAllCashRegisterTotals()); System.out.println("$");
            //CashRegisterTotals

            CashRegister B = new CashRegister();
            //customer B
            // "B" is a new customer
            B.addItem(13.5);
            //"B" add 1 Item
            B.addItem(38.5);
            //"B" add 2 Item
            B.addItem(122);
            //"B" add 3 Item
            B.removeItem(13.5);
            //"B" remove 1Item
           B.addItem(14);
            //"B" add 4 Item
            System.out.println("The number of item is: ");
            System.out.println(B.getItemCount());
            //"A" get ItemCount
            System.out.println("Total of the price is:");
            System.out.println(B.getAllCashRegisterTotals()); System.out.println("$");
            //CashRegisterTotals
        }
    }
}