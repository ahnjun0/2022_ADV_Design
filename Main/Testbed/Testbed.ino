// #include <Wire.h> Included in LiquidCrystal_I2C.h
#include <LiquidCrystal_I2C.h>
#include <pitches.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

/* Global Variable */

double angle_initial = 0; // 구부림 센서에서 처음 return되는 값. if 기준치 이상, ERROR.
int dis_initial = 0;//초음파 센서에서 처음 return되는 값. if 기준치 이하, ERROR.
int flex_pin = A4; // 구부림센서 핀 번호
int buzzer_pin = A8; // 부저(스피커) 핀 번호
int joystick_VRX_pin = A0; // 조이스틱 VRX 핀 번호
int joystick_VRY_pin = A1; // 조이스틱 VRY 핀 번호
int joystick_SW_pin = 13; // 조이스틱 SW 핀 번호



/* Reference Value */

double on_turtle_angle = 50; // 거북목 상태인 각도 기준값, 상수 값.
double on_turtle_distance = 30; // 거북목 상태인 거리 기준값, 상수 값



/* Temp Value */



/* Function Definition */



void setup() {
    Serial.begin(9600);

}



void loop() {

/*
 * 들어온 값을 if로 비교해서
 * 만약 그 값이 거북목 기준값보다 크다면
 * 1. buzzer() 함수를 이용해서 buzzer를 울리고
 * 2. i2c_lcd() 함수를 이용해서 lcd에 출력하고
 * 3. tx_message() 함수를 이용해서 휴대폰으로 보낸다.
*/
Serial.println(analogRead(flex_pin));
delay(500);
}
