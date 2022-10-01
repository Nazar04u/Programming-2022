#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() 
{
    map <int, string> s;
    s[1] = "Monday";
    s[2] = "Tuesday";
    s[3] = "Wendsday";
    s[4] = "Thursday";
    s[5] = "Friday";
    s[6] = "Saturday";
    s[7] = "Sunday";
    cout << "Enter number of day"<<endl;
    int b;
    cin >> b;
    while (b > 7) {
        b -=  7;
    }
    cout << s[b] << endl;
    return 0;



    
}
