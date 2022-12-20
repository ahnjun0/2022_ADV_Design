/* Global Variable */

int trigpin = 0; // 초음파 센서 trigPin
int echopin = 0; // 초음파 센서 echoPin

/* Reference Value */

double on_turtle; // 거북목 상태인 각도 기준값. 회귀분석을 통해 알아낼 예정이며, 상수 값.



/* Function Definition */


void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial1.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:

}