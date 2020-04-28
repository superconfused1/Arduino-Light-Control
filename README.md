# Arduino-Light-Control

This Arduino Light Control project and its makefiles are designed to run on an Arduno UNO R3 or an Arduino Deicimila.

Note:
This will likely work for other Arduino boards but... I only have the two models mentioned above.

Folder structure is broken into three (3) parts. One (1) for the UNO and one (1) for the Deicimila board and one (1) for the final draft of the complete Arduino sketch named FULL.

Inside these directories are sketches for the following functions with makefiles included:
Base (from the examples where the Arduino does nothing)
Blue
BlueFade
Green
GreenFade
Purple
Red
RedFade
TestFade (an attempt at making an attached LED light strip cycle through RGB)
White
WhiteFade
Yellow
YellowFade

A FULL directory also exists where all of the above functions have been combined into a sketch that can be controlled via serial commands sent via USB.
