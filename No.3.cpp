#include <iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

class Location
{
public:
     Location(double x, double y)
     {
         this->x = x;
         this->y = y;
     }
     double getx()
     {
         return x;
     }
     double gety()
     {
         return y;
     }
     double Distance(Location& location)
     {
         //sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
         return sqrt((x-location.getx())*(x-location.getx())
                     +(y-location.gety())*(y-location.gety()));
     }
     friend double Distance(Location& location1, Location& location2)
     {
         return sqrt((location1.getx()-location2.getx())
                     *(location1.getx()-location2.getx())
                     +(location1.gety()-location2.gety())
                     *(location1.gety()-location2.gety());
     }
private:
     double x,y;
};
int main()
{
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    Location location1(x1,y1);
    Location location2(x2,y2);

    return 0;
}
