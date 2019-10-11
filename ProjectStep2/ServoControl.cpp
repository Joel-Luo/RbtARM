#include "ServoControl.h"

#define DEBUG

// and it is controlled by PWM channel 0
#define PWM_CHANNEL 0
// This controls the max range of the PWM signal
#define RANGE 200

#define BCM2835_PWM_CLOCK_DIVIDER_1920 1920


ServoControl::ServoControl(int PinNmber):
m_PinNumber(PinNmber)
{
    m_Min_value = 9;
    m_Max_value = 30;
    
} // ServoControl::ServoControl() 


bool ServoControl::Initial()
{
	if (!bcm2835_init())
        return false;

    // Set the output pin to Alt Fun 5, to allow PWM channel 0 to be output there
    bcm2835_gpio_fsel(m_PinNumber, BCM2835_GPIO_FSEL_ALT5);
    // Clock divider is set to 16.
    // With a divider of 16 and a RANGE of 1024, in MARKSPACE mode,
    // the pulse repetition frequency will be
    // 19.2MHz/1920 /200= 50Hz, suitable for driving a DC motor with PWM
    bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_1920);
    bcm2835_pwm_set_mode(PWM_CHANNEL, 1, 1);
    bcm2835_pwm_set_range(PWM_CHANNEL, RANGE);
    // Vary the PWM m/s ratio between 1/RANGE and (RANGE-1)/RANGE
    // over the course of a a few seconds
   

    printf("Initial Servo....\n");
    bcm2835_pwm_set_data(PWM_CHANNEL, m_Min_value);
    bcm2835_delay(1000);

    return true;
}


bool ServoControl::Close()
{
	bcm2835_pwm_set_data(PWM_CHANNEL, m_Min_value);

    bcm2835_close();
    printf("Close ServoCntrol.\n");

    return true;
}

bool ServoControl::SetAngle(int angle)
{
	    if( angle < 0 || angle > 180)
	    {
	    	printf("ERROR: Set Over range.\n");
	     	return false ;	     
	    } // if
     
        int value = TranslateAngle2Value(angle);

        bcm2835_pwm_set_data(PWM_CHANNEL, value);
        bcm2835_delay(1000);
}


int ServoControl::TranslateAngle2Value(int angle)
{
	double ValuePerAngle = ((double)(m_Max_value - m_Min_value))/180.0;
    double value = ValuePerAngle * ((double)angle);


    printf("Set Angle:%d to Value:%f \n", angle, value);


    return (int)value;
}