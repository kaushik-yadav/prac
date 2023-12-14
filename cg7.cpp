#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
using namespace std;
int main()
{
int gd=DETECT,gm, i,j;
initgraph(&gd,&gm,NULL);
line(20,380,580,380); //platform
line(25,380,35,340); //leftleg
line(45,380,35,340);//right leg
line(35,310,25,330);//left hand
line(35,380,35,340); //leftleg
line(35,310,40,330); //left hand
line(35,340,35,310); //body
circle(35,300,10); //head
line(35,310,50,330); // right hand
line(50,330,50,280); //umbrella stick
line(15,280,85,280); //umbrella right
arc(50,280,180,360,35); //umbrella body
arc(55,330,360,180,5);//umbrella handle
 delay(10000);
 getch();
 return 0;
}