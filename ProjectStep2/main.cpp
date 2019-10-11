

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ServoControl.h"

using namespace RbtARM;

int main(int argc, char **argv)
{
    ServoControl * ServoCtrl = new ServoControl(18);

    
    
    char * temp = new char[20];

    int Min = 0;
    int Max = 180;
    int data = 0;
    int Dir = 1;

    ServoCtrl->Initial();


    printf("Enter Angle. q to quite.\n");

    int i = 0;
    do 
    {
        //scanf( "%s", temp);


        if( strcmp(temp, "q") == 0 ){
            printf("Exit.\n" );
            break;
        } // if       

        else if( strcmp(temp, "r") == 0  )
        {
            data = Min;
        } // else if

        else 
        {
            //int v = atoi(temp);
            //if( v > Max ) 
            //    data = Max;
            //else if( v < Min )
            //    data = Min;
            //else 
            //    data = v;
            
            data+= (9*Dir);
            if(data > Max ){
                data = Max;
                Dir = -1;
                i++;
            }  // if
            else if ( data < Min )
            {
                data = Min;
                Dir = 1 ;
            }  // else 

            printf("Insert angle %d\n", data );
        }  // else

        ServoCtrl->SetAngle(data);

    }while(true&& i < 10);

        

    ServoCtrl->Close();

    return 0;
}