#include <mbed.h>
#include "Encoder/Encoder.hpp"
#include "PIDController/PIDController.hpp"

class Test
{
public:
    Test(PinName interrupt_in_pin, PinName digital_in_pin, PinName dir_pin, PinName pwm_pin);
    void setDeg(float deg_);
    void motor_ctr();

private:
    float deg;
    float deg_en;
    float duty;
    Encoder en;
    PIDController pid;
    DigitalOut dir;
    PwmOut speed;
    bool dir_rotate;

};
