#include<Wire.h>

#define button1 2
#define button2 3  

volatile int buttons[2] = {0};

void setup() {
    Serial.begin(9600);
    Wire.begin(2);

    Wire.onRequest(fun);

    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
}

void loop() {

    buttons[0] = digitalRead(button1);
    buttons[1] = digitalRead(button2);

}

void fun(){
    
  byte transmission[2];
  transmission[0] = buttons[0];
  transmission[1] = buttons[1];
  
  Wire.write(transmission, sizeof(transmission));

}
