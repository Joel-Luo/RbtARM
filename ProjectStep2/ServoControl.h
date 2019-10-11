#ifndef SERVO_CONTROL_H
#define SERVO_CONTROL_H

#include <bcm2835.h>
#include <stdio.h>


namespace RbtARM
{
    class ServoControl
    {
        private :
            int m_PinNumber;
            int m_Min_value;
            int m_Max_value;

            int TranslateAngle2Value(int angle);

        public :
            ServoControl(int PinNmber);

            bool Initial();

            bool Close();

            bool SetAngle(int angle);


    } // ServoControl  

} // namespace



#endif SERVO_CONTROL_H