#include "E2BOX.h"
E2BOX::E2BOX(PinName tx, PinName rx, int baud):imu_(tx,rx,baud) {
    Serial imu_(tx, rx, baud);
}

void E2BOX::Data(float* euler, float* position) {

    char* start = strchr(buf, '*');
    if (start != NULL) {
        start++;

        char* token = strtok(start, ",");
        if (token != NULL) {
            euler[0] = atof(token); 

            token = strtok(NULL, ",");
            if (token != NULL) {
                euler[1] = atof(token); 

                token = strtok(NULL, ",");
                if (token != NULL) {
                    euler[2] = atof(token); 

                    token = strtok(NULL, ",");
                    if (token != NULL) {
                        position[0] = atof(token);

                        token = strtok(NULL, ",");
                        if (token != NULL) {
                            position[1] = atof(token);

                            token = strtok(NULL, ",");
                            if (token != NULL) {
                                position[2] = atof(token);
                        
                            }
                        }                       
                    }                     
                }
            }
        }
    }
}
void E2BOX::Parse() {
    for(int i=0;i<64;i++) {
    char a = imu_.getc();
    if(a == 0x0A) Data(euler, position);
    else buf[i] = a;
    }
}

void E2BOX::GetEuler(float& roll, float& pitch, float& yaw) {
    roll = euler[0];
    pitch = euler[1];
    yaw = euler[2];
}

void E2BOX::GetPosition(float& x, float& y, float& z) {
    x = position[0];
    y = position[1];
    z = position[2];
}