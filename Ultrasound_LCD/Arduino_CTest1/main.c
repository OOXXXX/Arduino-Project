//
// Created by Patrick on 2022/11/5.
//
#include <stdio.h>

void LedFlash16() {
    printf("There's something behind the sensor!\nLED flashes at 1.25 Hz\nBuzzer makes sound at 300Hz");
}

void LedFlash11() {
    printf("There's something behind the sensor!\nLED flashes at 2.5 Hz\nBuzzer makes sound at 700Hz");
}

void LedFlash6() {
    printf("There's something behind the sensor!\nLED flashes at 5 Hz\nBuzzer makes sound at 1100Hz");
}

void LedNotFlash() {
    printf("There's nothing behind the sensor!\nLED not flash\nBuzzer makes no sound");
}

int main() {
    int Distance;
    printf("Please enter the distance of the object to sensor: ");
    scanf("%d", &Distance);
    if (Distance <= 16 && Distance >= 11) {
        LedFlash16();
    }
    else if (Distance < 11 && Distance >= 6) {
        LedFlash11();
    }
    else if (Distance < 6) {
        LedFlash6();
    }
    else  {
        for (int i = 0; i < 3; ++i) {
            LedNotFlash();
        }
    }

    return 0;
}

