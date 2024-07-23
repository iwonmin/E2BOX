#include "mbed.h"
#include "E2BOX.h"

Serial pc(USBTX, USBRX,115200);
E2BOX imu(PB_10,PC_5,115200);
float roll, pitch, yaw;
int main() {

    while(1) {
        imu.Parse();
        imu.GetEuler(roll, pitch, yaw);
        pc.printf("Roll : %.2f Pitch : %.2f, Yaw : %.2f\r\n",roll,pitch,yaw);
        wait_us(1000);
    }
}