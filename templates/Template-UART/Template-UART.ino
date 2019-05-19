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

int byteCount = 0;
int intValue[4];
float floatValue[4];



void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  //This must always be called first
  checkSerial();

  // === ADD CUSTOM TOOL CODE HERE ===
  if (intValue == 0) {
    digitalWrite(13, LOW);
  }
  else {
    if (intValue[0] > 32) intValue[1] = 32;
    for (int i = 0; i < intValue[1]; i++) {
      digitalWrite(13, HIGH);
      delay(500);
      digitalWrite(13, LOW);
      delay(500);
    }
  }

  // === END CUSTOM CODE ===
}

/*
  Reads four 4-byte integers or floats. The value sent from the robot will be available
  in the intValue or floatValue variables.
*/
void checkSerial() {
  while (Serial.available() > 0) {
    int varId = byteCount / 4;  // Which variable
    int innerId = byteCount % 4; // Which byte within variable
    
    intConvert.asBytes[4 - innerId] = Serial.peek();
    floatConvert.asBytes[4 - innerId] = Serial.read();

    if (byteCount % 4 == 3) {
      intValue[varId] = intConvert.asInt;
      floatValue[varId] = floatConvert.asFloat;
    }
    byteCount++;
    byteCount %= 16;
  }
}
