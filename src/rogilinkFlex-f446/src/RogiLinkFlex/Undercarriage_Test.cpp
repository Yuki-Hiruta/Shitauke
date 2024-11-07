#include <mbed.h>
#include "Undercarriage_Test.hpp"


Test::Test(PinName interrupt_in_pin, PinName digital_in_pin, PinName dir_pin, PinName pwm_pin)
: en(interrupt_in_pin, digital_in_pin, 2048, false)
, pid(0.1, 0, 0, 1 * 1000)
, dir(dir_pin)
, speed(pwm_pin)
, dir_rotate(0)
{
    speed.period_us(100);
}

void Test::setDeg(float deg_)
{
    deg = deg_;
}

void Test::motor_ctr()
{
    deg_en = (en.getCount() / 2048) * 360;
    duty = pid.calculate(deg - deg_en);
    if(duty < 0)
    {
        dir_rotate = 1;
    }
    else
    {
        dir_rotate = 0;
    }
    if(fabs(duty) > 1)
    {
        duty = 1;
    }
    dir.write(dir_rotate);
    speed.write(fabs(duty));
}

