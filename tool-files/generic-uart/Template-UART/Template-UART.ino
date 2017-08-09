union intConverter {
  byte asBytes[4];
  int asInt;
} intConvert;

union floatConverter {
  byte asBytes[4];
  int asFloat;
} floatConvert;

int count = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  if (Serial.available() > 0) {
    intConvert.asBytes[4 - count] = Serial.peek();
    floatConvert.asBytes[4 - count] = Serial.read();

    if (count == 3) {
      int intValue = intConvert.asInt;
      float floatValue = floatConvert.asFloat;

      // Custom code goes here.
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

    }

    count++;
    count %= 4;
  }
}
