#include <iostream>
#include <Hotel.h>

int main()
{
   int noFloor, noMainCorr, noSubCorr, noLights, noACs;
   //bool humanMovement = false;
   char  motion = ' ';

   cout <<"Enter No of Floors : " ;
   cin >> noFloor;
   cout << endl;

   cout <<"Enter No of Main Corridors Per Floor : " ;
   cin >> noMainCorr;
   cout << endl;

   cout <<"Enter No of Sub Corridors Per Floor  : " ;
   cin >> noSubCorr;
   cout << endl;

   cout <<"Enter No of Lights per Corridors : " ;
   cin >> noLights;
   cout << endl;

   cout <<"Enter No of ACs per Corridors : " ;
   cin >> noACs;
   cout << endl;

   Hotel * hotelObj = new Hotel(noFloor, noMainCorr, noSubCorr, noLights, noACs);
   hotelObj->initializeFloors();
   int floorNo;
   cout<<"Enter Floor No: ";
   cin >> floorNo ;
   cout << endl;
   int powerConsumption = hotelObj->powerConsumptionPerFloor(floorNo);
   cout << "Power Consumption at Floor No: " << floorNo << " is " << powerConsumption << endl;

   cout << "********************************" << endl;
   hotelObj->getStatus();
   cout << "********************************" << endl;

   while(true)
   {
      cout << "Input Motion Detection Sensor (Y/N) or (y/n): ";
      cin >> motion;

      if(motion == 'E' || motion == 'e')
         break;
      switch (motion)
      {
         case 'y':
		{
		}
         case 'Y':
		{
            int floorNo, subCorrNo;
            cout<<"Enter the floor No: ";
            cin>>floorNo;
            cout<<"Enter the Sub Corridor No: ";
            cin>>subCorrNo;
            hotelObj->updateSubCorrStatusOnMotion(floorNo, subCorrNo);

            cout << "********************************" << endl;
            hotelObj->getStatus();
            cout << "********************************" << endl;
            int powCons = hotelObj->powerConsumptionPerFloor(floorNo);
            cout << "Power Consumption at Floor No: " << floorNo << " is " << powCons << endl;

            hotelObj->controlPowerConsumptionOnMovement(floorNo, subCorrNo);

            cout << "********************************" << endl;
            hotelObj->getStatus();
            cout << "********************************" << endl;
		}
            break;
         case 'n':
		{
		}
		
         case 'N':
		{
            cout << " Motion has not been detected " << endl;
		}
            break;

         default:
            cout << " Unknown input from Sensor " << endl;
            break;
      }
   }
   

   return 0;
}
