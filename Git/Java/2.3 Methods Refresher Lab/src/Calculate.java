public class Calculate
{

    public static void main (String [ ] args)
    {
        //initialize all variable
        Areas area = new Areas ();
        //initialize variable for (radius. wide, height)
        double radius = 3, wide1 = 6, height = 9, wide2 = 12;
        double areaCircle = area.areaCircle(radius);
        double areaSquare = area.areaSquare(wide1);
        double areaTriangle = area.areaTriangle(wide1, height);
        double areaRectangle = area.areaRectangle(wide1, height);
        double areaTrapezoid = area.areaTrapezoid(wide1, wide2, height);
        //print out the 5 areas
        System.out.println("The area of a circle of radius " + radius +  " is " + areaCircle);
        System.out.println("The area of a square of wide " + wide1 + " is " + areaSquare);
        System.out.println("The area of a triangle of wide " + wide1 + " and height " + height + " is " + areaTriangle);
        System.out.println("The area of a rectangle of wide " + wide1+ " and height " + height + " is " + areaRectangle);
        System.out.println("The area of a trapezoid of wide1 " + wide1 + " wide2 " + wide2 + " and height " + height +" is " + areaTrapezoid);
    }
}
