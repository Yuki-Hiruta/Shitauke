#include "UartLink.hpp"
#include "Undercarriage_Test.hpp"

UartLink uart1(USBTX, USBRX, 115200);
Test undercarriage;
UartLinkSubscriber<float> sub(uart1, 1);

void sub_callback(float deg_)
{
    undercarriage.setDeg(deg_);
    undercarriage.motor_ctr();
}

int main()
{
    sub.set_callback(sub_callback);
}