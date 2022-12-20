#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <pitches.h>

LiquidCrystal_I2C lcd(0x00, 16, 2);

/* Global Variable */

double angle_initial = 0; // 구부림 센서에서 처음 return되는 값. if 기준치 이상, ERROR.
int flex_pin = 0; // 구부림센서 핀 번호
int buzzer_pin = 0; // 부저(스피커) 핀 번호
int joystick_VRX_pin = 0; // 조이스틱 VRX 핀 번호
int joystick_VRY_pin = 0; // 조이스틱 VRY 핀 번호
int joystick_SW_pin = 0; // 조이스틱 SW 핀 번호



/* Reference Value */

double on_turtle; // 거북목 상태인 각도 기준값. 회귀분석을 통해 알아낼 예정이며, 상수 값.



/* Function Definition */

double resist_to_angle(void);
void buzzer(int length, int time);
void i2c_lcd(char* text);
int joystick(void);

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial1.begin(9600); // 초음파센서에서 Data Rx
    Serial2.begin(9600); // 스마트폰으로 Data Tx

    angle_initial = resist_to_angle();
    if (angle_initial >= on_turtle) {
        buzzer(500,4);
    }



}

void loop() {
    // put your main code here, to run repeatedly:

}


/**
 * @brief 저항값을 각도로 만들기 위한 함수.
 * @details 함수 내에서 휨센서로 저항값을 입력받고, 미리 계산된 선형회귀 식에 따라 각도 값을 return한다.
 * @param void
 * @return double 값의 각도를 return한다.
 */
double resist_to_angle(void) {
    double resist = analogRead(0); // 구부림 센서의 return value
    double angle = 1.0 * resist + 0.0; // 선형회귀로 식 구하기
    return angle;
}



/**
 * @brief 거북목 상태일 때 작동시킬 Buzzer(Speaker).
 * @param length 작동시킬 길이. ms 단위.
 * @param time 작동시킬 횟수. (예를 들자면 삑 삑 삑 삑)
 */
void buzzer(int length, int time) {
    for (int k = 0; k < time; k++) {
        tone(buzzer_pin, NOTE_C5, length);
        delay(time/3);
    }
}



/**
 * @brief text로 들어온 파일을 16*2 LCD에 출력하도록 하는 함수입니다.
 * @details 입력은 16자 전부가 들어옵니다.
 * @param text pointer 방식으로 char* 문자열이 들어옵니다
 */
void i2c_lcd(char* text) {

}



/**
 * @brief 조이스틱의 방향에 따라, 출력값을 결정.
 * @details 조이스틱이 왼쪽으로 가면 1을 출력한다거나 하는 규칙을
 *           직접 본인이 정하셔서 doxygen @return에 적어주세요
 *           조이스틱의 동작 원리는 https://blog.naver.com/boilmint7/220927175653
 *           해당 링크 속의 블로그를 참고하시면 편할겁니다.
 *           핀 번호는 상단에 적혀있는 joystick_NNN_value 변수를 사용해주세요
 * @param void
 * @return int 
 */
int joystick(void){

}