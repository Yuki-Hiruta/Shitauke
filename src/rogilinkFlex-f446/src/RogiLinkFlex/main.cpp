#include "UartLink.hpp"
#include "Undercarriage_Test.hpp"
#include "Dif_everything.hpp"

UartLink uart1(PC_11, PC_10, 115200);
Test uc1(interrupt_in_pin_e1, digital_in_pin_e1, dir_pin_m1, pwm_pin_m1);
Test uc2(interrupt_in_pin_e2, digital_in_pin_e2, dir_pin_m2, pwm_pin_m3);
Test uc3(interrupt_in_pin_e3, digital_in_pin_e3, dir_pin_m2, pwm_pin_m3);
UartLinkSubscriber<float> sub(uart1, 1);

void sub_callback(float deg_)
{
    uc1.setDeg(deg_);
    uc2.setDeg(deg_);
    uc3.setDeg(deg_);

    uc1.motor_ctr();
    uc2.motor_ctr();
    uc3.motor_ctr();
}

int main()
{
    sub.set_callback(sub_callback);
}