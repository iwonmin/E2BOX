#include "mbed.h"
#include "string.h"
#include "stdlib.h"
class E2BOX {
    public:
        E2BOX(PinName tx, PinName rx, int baud);
        void Parse();
        void Data(float*, float*); //euler[3], pos[3]
        void GetEuler(float&, float&, float&);
        void GetPosition(float&, float&, float&);
    private:
        Serial imu_;
        float euler[3];
        float position[3];
        char buf[64] = "";
};