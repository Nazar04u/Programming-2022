#include<iostream>
#include<cmath>
using namespace std;
/* Users input() 3 paramaters of line and you need to check if they create triangle. if so , calculate a area of triangle*/
float area_of_triangle(float a1, float b1, float a2, float b2, float a3, float b3)
{
    if (a1 != a2 and a1 != a3 and a2 != a3) {
        /* if a1==a2 or a2==a3 or a1==a3 then two line are paralel and the don't create a triangle*/
        /*calculating their coordinates*/
        float x1 = (b1 - b2) / (a1 - a2);
        float y1 = a1 * x1 + b1;
        float x2 = (b2 - b3) / (a2 - a3);
        float y2 = a2 * x2 + b2;
        float x3 = (b3 - b1) / (a3 - a1);
        float y3 = a3 * x3 + b3;
        if (x1 != x2 != x3) {
            /* if x1==x2==x3 then all lines  cross each other in the same point and don't create a triangle*/
            /* Calculate a size if sides of triangle knowing their coordinates*/
            float side1 = pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5);
            float side2 = pow(pow(x3 - x2, 2) + pow(y3 - y2, 2), 0.5);
            float side3 = pow(pow(x1 - x3, 2) + pow(y1 - y3, 2), 0.5);
            float piv_perimetr = (side1 + side2 + side3) / 2;
            return pow(piv_perimetr * (piv_perimetr - side1) * (piv_perimetr - side2) * (piv_perimetr - side3), 0.5); /* Formula of geron to calculate area of triangle*/

        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}
int main()
{
    cout << "Enter parameters of first line" << endl;
    float a1;
    cin >> a1;
    float b1 ;
    cin >> b1;
    cout << "Enter parameters of second line" << endl;
    float a2 ;
    cin >> a2;
    float b2 ;
    cin >> b2;
    cout << "Enter parameters of third  line" << endl;
    float a3 ;
    cin >> a3;
    float b3 ;
    cin >> b3;
    cout << "Suare of triangle = " << area_of_triangle(a1, b1, a2, b2, a3, b3);
    return 0;
}
