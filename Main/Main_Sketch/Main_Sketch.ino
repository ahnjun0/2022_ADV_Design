#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/* Global Variable */
double angle_initial = 0; // 구부림 센서에서 처음 return되는 값 if 기준치 이상, ERROR

int flex_pin = 0;
/* temporary Varialbe */
double on_turtle; // 거북목 상태인 각도 기준값. 회귀분석을 통해 알아낼 예정

/* Function Definition */
double resist_to_angle(void);

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial1.begin(9600); // 초음파센서에서 Data Rx
    Serial2.begin(9600); // 스마트폰으로 Data Tx

    angle_initial = resist_to_angle();
    if (angle_initial >= on_turtle) {

    }



}

void loop() {
    // put your main code here, to run repeatedly:

}

double resist_to_angle(void) {
    // 선형회귀로 식 구하기
    double resist = analogRead(0); // 구부림 센서의 return value
    double angle = 1.0 * resist + 0.0;
    return angle;
}