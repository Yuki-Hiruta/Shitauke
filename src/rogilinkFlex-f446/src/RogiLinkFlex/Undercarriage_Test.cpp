#include <mbed.h>
#include "Undercarriage_Test.hpp"


Test::Test()
: en(PA_0, PA_1, 2048, false)
, pid(0.5, 0, 0, 1 * 1000)
, dir(PA_2)
, speed(PA_3)
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

