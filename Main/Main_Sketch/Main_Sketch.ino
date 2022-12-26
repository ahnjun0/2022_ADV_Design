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

double resist_to_angle(void);
int distance(void);
void buzzer(int length, int time);
void i2c_lcd(String text, int k);
void tx_message(char* message);
int joystick(void);



void setup() {
    Serial.begin(9600);
    Serial1.begin(9600); // 초음파센서에서 Data Rx
    Serial2.begin(9600); // 스마트폰으로 Data Tx
    
    lcd.begin(); //LCD 초기화
    lcd.backlight(); //백라이트 on

    pinMode(joystick_SW_pin, INPUT_PULLUP);//z축 버튼  

    lcd.clear();
    i2c_lcd("  Press Button  ", 0);
}



void loop() {

/*
 * 들어온 값을 if로 비교해서
 * 만약 그 값이 거북목 기준값보다 크다면
 * 1. buzzer() 함수를 이용해서 buzzer를 울리고
 * 2. i2c_lcd() 함수를 이용해서 lcd에 출력하고
 * 3. tx_message() 함수를 이용해서 휴대폰으로 보낸다.
*/

    if ( joystick() == 5 ) {
        dis_initial = distance();
        if (dis_initial > 100) dis_initial = 100; //모니터에서 인간까지 거리 상한값.
        lcd.clear();
        i2c_lcd(" Init Success!! ", 0);
        i2c_lcd("Distance : "+String(dis_initial)+"cm", 1);        
    }

    if (dis_initial != 0) {
        double angle = resist_to_angle();
        int now_dis = distance();
        if (dis_initial > 100) dis_initial = 100;
        
        if ((angle < on_turtle_angle) && (dis_initial - now_dis > on_turtle_distance)) {
            char* message = "Warning!! Stretch your neck plz!\nWhatch this video.\nhttps://www.youtube.com/watch?v=TWGXLs5a8Ig\n\n";
            tx_message(message);
            lcd.clear();
            i2c_lcd("   Warning!!!   ",0);
            i2c_lcd("Angle : "+String(angle)+"deg", 1);
            buzzer(100, 3);
        }
    }
}



/**
 * @brief 저항값을 각도로 만들기 위한 함수.
 * @details 함수 내에서 휨센서로 저항값을 입력받고, 미리 계산된 선형회귀 식에 따라 각도 값을 return한다.
 * @param void
 * @return double 값의 각도를 return한다.
 */
double resist_to_angle(void) {
    double resist = analogRead(flex_pin); // 구부림 센서의 return value
    double angle = 0.4795 * resist - 144.6579; // 선형회귀로 식 구하기
    return angle;
}



/**
 * @brief 거북목 상태일 때 작동시킬 Buzzer(Speaker).
 * @param length 작동시킬 길이. ms 단위.
 * @param time 작동시킬 횟수. (ex. 삑 삑 삑 삑)
 */
void buzzer(int length, int time) {
    for (int k = 0; k < time; k++) {
       tone(buzzer_pin, NOTE_C6, length);
    }
}



/**
 * @brief text로 들어온 파일을 16*2 LCD에 출력하도록 하는 함수입니다.
 * @details 입력은 16자 전부와, 줄 번호가 들어옵니다. (0번 줄, 1번 줄)
 *           https://popcorn16.tistory.com/206 참고하시면 좋습니다.
 * @param text pointer 방식으로 char* 문자열이 들어옵니다
 * @param k int 방식으로 줄 번호를 알려줍니다. (k = 0일때 16x2에서 0번째 줄)
 */
void i2c_lcd(String text, int k) {
    lcd.setCursor(0, k);
    lcd.print(text);
}


/**
 * @brief 조이스틱의 방향에 따라, 출력값을 결정.
 * @details 조이스틱의 동작 원리는 https://blog.naver.com/boilmint7/220927175653
 *           해당 링크 속의 블로그를 참고하시면 편할겁니다.
 *           핀 번호는 상단에 적혀있는 joystick_NNN_value 변수를 사용해주세요
 * @param void
 * @return int 
 */
int joystick(void){
    int joy_x = analogRead(joystick_VRX_pin);
    int joy_y = analogRead(joystick_VRY_pin);
    bool joy_z = digitalRead(joystick_SW_pin);
    int control = 0;
  
    if (joy_x < 100) control = 3;
    if (joy_x > 100) control = 4;
    if (joy_y < 100) control = 1;
    if (joy_y > 100) control = 2;
    if (joy_z == LOW) control = 5; // Using INPUT_PULLUP

    delay(100);

    return control;
}



/**
 * @brief 모니터와 이용자의 거리를 전송받는 함수입니다.
 * @details
 * @param void
 * @return int
 */
int distance(void){
    if (Serial1.available()) {
        int dis;
        String string = Serial1.readStringUntil('\n');
        Serial.println(string);
        dis = string.toInt();
        if (dis > 0) return dis;

     } 
}



/**
 * @brief 휴대폰으로 메시지를 전송하는 함수입니다.
 * @details 현재 각도와 영상 링크 등이 담긴 텍스트 메시지를
 *                   BLuetooth Terminal HC-05 APP으로 전송
 * @param message 
 */
void tx_message(char* message) {
    Serial2.println(message);
}
