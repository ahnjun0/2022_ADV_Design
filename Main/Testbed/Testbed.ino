int joystick_VRX_pin = A0; // 조이스틱 VRX 핀 번호
int joystick_VRY_pin = A1; // 조이스틱 VRY 핀 번호
int joystick_SW_pin = 13; // 조이스틱 SW 핀 번호


void joystick(void);

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(joystick_SW_pin, INPUT_PULLUP);

}

void loop() {
    // put your main code here, to run repeatedly:
    joystick();
}

void joystick(void) {
    int joy_x = analogRead(joystick_VRX_pin);
    int joy_y = analogRead(joystick_VRY_pin);
    bool joy_z = digitalRead(joystick_SW_pin);
    int control = 0;

    Serial.print("joy_x : ");
    Serial.println(joy_x);
    Serial.print("joy_y : ");
    Serial.println(joy_y);
    Serial.print("joy_z : ");
    Serial.println(joy_z);
    Serial.println();
    Serial.println();
  
//    if (joy_x < 512) control = 3;
//    if (joy_x > 512) control = 4;
//    if (joy_y < 512) control = 1;
//    if (joy_y > 512) control = 2;
//    if (joy_z == LOW) control = 5;

    delay(500);

    return;
}
