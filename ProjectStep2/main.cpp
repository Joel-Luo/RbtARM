

#include <stdio.h>
#include <ServoControl.h>

using namespace RbtARM;

int main(int argc, char **argv)
{
    ServoControl * ServoCtrl = new ServoControl(18);

    
    
    char temp = '\0';

    int Min = 0;
    int Max = 180;
    int data = 0;

    ServoCtrl->Initail();


    printf("Enter W/S to Up/Down. q to quite.\n");

    do 
    {
        scanf( "%c", &temp);

        if( temp == 'q' ){
            printf("Exit.\n" );
            break;
        } // if

        else if( temp == 'w' )
        {
            data+=1;
            if( data > Max )
                data = Max ;
        }  // else if
        
        else if( temp == 's' )
        {
            data-=1;
            if( data < Min )
                data = Min ;
        } // else if

        else if( temp == 'r' )
        {
            data = Min;
        } // else if

        ServoCtrl->SetAngle(data);

    }while(true);

    ServoCtrl->Close();

    return 0;
}