#include <stdio.h>
#include <stdbool.h>


void readAccelerometerData(double accelerometerData[3]) {
  
    accelerometerData[x] = 0x0000;
    accelerometerData[y] = 0xFF00;
    accelerometerData[z] = 0x013B;
}


bool isMoving(const double accelerometerData[3]) {
    
    const double threshold = 1.0;
    double magnitude = 0.0;
    for (int i = 0; i < 3; ++i) {
        magnitude += accelerometerData[i] * accelerometerData[i];
    }
    magnitude = sqrt(magnitude);

    return magnitude > threshold;
}

int main() {
    
    double accelerometerData[3];
    readAccelerometerData(accelerometerData);

    bool moving = isMoving(accelerometerData);

   
    if (moving) {
        printf("Tag is moving.\n");
    } else {
        printf("Tag is stationary.\n");
    }

    return 0;
}
