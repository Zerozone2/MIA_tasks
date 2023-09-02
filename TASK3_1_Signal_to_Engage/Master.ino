#include<Wire.h>

#define led 5

volatile int buttons[2] = {0};
volatile int but1 = 0;
volatile int but2 = 0;

void setup() {
    Serial.begin(9600);
    Wire.begin();
    pinMode(led, OUTPUT);
}

void loop() {

    Wire.requestFrom(2, 4);
    byte i=0;
    while( Wire.available() ){
        buttons[i++] = Wire.read();
    }

    //Serial.println(buttons[0] + " " + buttons[1]);

    but1 = buttons[0]; but2 = buttons[1];

    if( but1 == HIGH && but2 == HIGH ){
      delay(400);
      analogWrite(led, 255);
      Serial.println("Glitch");
    }else if( but1 == HIGH && but2 == LOW ){
      delay(400);
      analogWrite(led, 130);
      Serial.println("Vector focused");
    }else if( but1 == LOW && but2 == HIGH ){
      delay(400);
      analogWrite(led, 195);
      Serial.println("Vector distracted");
    }else{
      delay(400);
      analogWrite(led, 0);
      Serial.println("");
    }
    
}
