/**
 * CashRegister
 * Get the total number of items and the total price of each item
 * Calculate the total price
 * Users can add or subtract items
 * To calculate the total price for a day.
 */
public class CashRegister
{
    private int itemCount;
    private double CashRegisterTotal;
    public static double allCashRegisterTotals=0;

    /**
     * Initial the variable
     */
    public CashRegister()
    {
        CashRegisterTotal = 0;
    }

    /**
     * Methods of add item
     * @param addItem
     */
    public void addItem(double addItem)
    {
        itemCount ++;
        CashRegisterTotal =  CashRegisterTotal + addItem;
        allCashRegisterTotals = allCashRegisterTotals + addItem;
    }

    /**
     * Methods of remove item
     * @param removeItem
     */
    public void removeItem (double removeItem)
    {
        itemCount--;
        if(CashRegisterTotal - removeItem >= 0)
        {
            CashRegisterTotal = CashRegisterTotal - removeItem;
            allCashRegisterTotals = allCashRegisterTotals - CashRegisterTotal;
        }
    }


    /**
     * Methods of getCashRegisterTotal()
     * @return getCashRegisterTotal
     */
    public double getCashRegisterTotal()
    {
        return CashRegisterTotal;
    }

    /**
     *Method of  getCount
     * @return getItemCount
     */
    public int getItemCount()
    {
        return itemCount;
    }

    /**
     * Method of  getAllCashRegisterTotals
     * @return getAllCashRegisterTotals
     */
    public double getAllCashRegisterTotals()
    {
        return CashRegisterTotal;
    }

    /**
     * Method of clear
     */
    public void clear()
    {
        itemCount = 0;
        CashRegisterTotal = 0;
    }

}