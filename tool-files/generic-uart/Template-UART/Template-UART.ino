/*
  This template is a base for tools that use an arduino and will communicate over uart-serial
  (i.e. with a single microcontroller attached. See i2c for talking to multiple arduinos or other boards).
  No changes need to be made for connecting over USB vs hardware pins (remember to use a proper 
  logic converter for connecting over pins).
  Any code that uses data received from the serial connection should be added to the relevant section 
  in the checkSerial function.
*/

union intConverter {
  byte asBytes[4];
  int asInt;
} intConvert;

union floatConverter {
  byte asBytes[4];
  float asFloat;
} floatConvert;

int count = 0;


void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  checkSerial();
}

/*
Reads 4-byte integers or floats. The value sent from the robot will be available 
in the intValue or floatValue variables.
*/
void checkSerial() {
  while (Serial.available() > 0) {
    intConvert.asBytes[4 - count] = Serial.peek();
    floatConvert.asBytes[4 - count] = Serial.read();

    if (count == 3) {
      int intValue = intConvert.asInt;
      float floatValue = floatConvert.asFloat;

      // === REPLACE WITH CUSTOM CODE THAT USES SERIAL DATA ===
      if (intValue == 0) {
        digitalWrite(13, LOW);
      }
      else {
        if (intValue > 32) intValue = 32;
        for (int i = 0; i < intValue; i++) {
          digitalWrite(13,HIGH);
          delay(500);
          digitalWrite(13,LOW);
          delay(500);
        }
      }
      // === END CUSTOM CODE ===
    }
    count++;
    count %= 4;
  }
}
