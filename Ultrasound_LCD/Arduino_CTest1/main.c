//
// Created by Patrick on 2022/11/5.
//
#include <stdio.h>

void LedFlash16() {
    printf("There's something behind the sensor!\nLED flashes at 0.8Hz\nBuzzer makes sound at 400Hz");
}

void LedNotFlash() {
    printf("There's nothing behind the sensor!\nLED not flash\nBuzzer makes no sound");
}

int main() {
    int Distance;
    printf("Please enter the distance of object to sensor: ");
    scanf("%d", &Distance);
    if (Distance < 16) {
        LedFlash16();
    }
    else {
        LedNotFlash();
    }

    return 0;
}

