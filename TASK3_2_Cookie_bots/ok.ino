#define xFull 5
#define yFull 6

const int trigPins[4] = {2, 4, 6, 8}; 
const int echoPins[4] = {3, 5, 7, 9};

float xDistance[2] = {0};
float yDistance[2] = {0};

void setup() {
  
    Serial.begin(9600);

    for( int i=0; i<4; i++ )
      pinMode(trigPins[i], OUTPUT);

    for( int i=0; i<4; i++ )
      pinMode(echoPins[i], INPUT);

}

void loop() {

    // loop for reading each sensor reading 
    for( int i=0; i<4; i++ ){
      long distance;
      digitalWrite(trigPins[i], LOW);
      delayMicroseconds(2);
      digitalWrite(trigPins[i], HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPins[i], LOW);

      distance = pulseIn(echoPins[i], HIGH);

      // separating x-axis sensors from y-axis sensors using parity
      if( i&1 ){
        yDistance[i/2] = microsecondsTometers(distance);
      }else{
        xDistance[i/2] = microsecondsTometers(distance);
      }
    }

    // if the left sensor exceed reading of 3, the result will depend on the right sensor. The same is done with up and down
    float x_final = xDistance[1] > 3 ? 5 - xDistance[0] : xDistance[1];
    float y_final = yDistance[1] > 3 ? 6 - yDistance[0] : yDistance[1];

    Serial.print( x_final );
    Serial.print( ", " );
    Serial.print( y_final );
    Serial.println();
    
}

// converting time to length using sound speed
float microsecondsTometers(long microseconds) {
   return microseconds / 29.0 / 2.0 / 100.0;
}