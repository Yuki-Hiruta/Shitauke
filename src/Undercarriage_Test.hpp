#include <mbed.h>
#include "Encoder/Encoder.hpp"
#include "PIDController/PIDController.hpp"

class Test
{
public:
    Test();
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

Test::Test()
: en(PA_0, PA_1, 2048, false)
, pid(0.5, 0, 0, 1 * 1000)
, dir(PA_2)
, speed(PA_3)
, dir_rotate(0)
{
    speed.period_us(100);
}