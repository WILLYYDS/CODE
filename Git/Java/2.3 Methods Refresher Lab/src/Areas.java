public class Areas {

    /**
     * return area of circle
     * @param radius
     * @return area of Circle
     */
    public double areaCircle (double radius)
    {
         return Math.PI * Math.pow (radius, 2);
    }


    /**
     * return area of  square
     * @param wide1
     * @return area of Square
     */
    public double areaSquare (double wide1)
    {
        return Math.pow(wide1, 2);
    }


    /**
     * return area of triangle
     * @param wide1
     * @param height
     * @return area of Triangle
     */
    public double areaTriangle ( double wide1, double height)
    {
        return (wide1 * height) / 2.0;
    }


    /**
     * return area of rectangle
     * @param wide1
     * @param height
     * @return area of Rectangle
     */
    public double areaRectangle (double wide1, double height)
    {
            return wide1 * height;
    }


    /**
     * return area of Trapezoid
     * @param wide1
     * @param wide2
     * @param height
     * @return area of Trapezoid
     */
    public double areaTrapezoid (double wide1, double wide2, double height)
    {
        return ((wide1 + wide2) * height) / 2.0;

    }

}






























