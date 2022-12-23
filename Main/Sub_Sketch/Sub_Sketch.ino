/* Global Variable */

int trigpin = 2; // 초음파 센서 trigPin
int echopin = 3; // 초음파 센서 echoPin

/* Reference Value */


/* Function Definition */


void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial1.begin(9600);
    pinMode(trigpin, OUTPUT);
    pinMode(echopin, INPUT);  
}

void loop() {
    // put your main code here, to run repeatedly:
    digitalWrite(trigpin, HIGH);
    delay(10);
    digitalWrite(trigpin, LOW);
    float duration = pulseIn(echopin, HIGH);
    float distance = duration * 340 / 10000 / 2;
    int dis_int = (int)distance;
    String dis_str = String(dis_int);
    delay(50);
    Serial1.println(dis_str);
    Serial.println(dis_str);
}

