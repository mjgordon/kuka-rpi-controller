/*
  This template is a base for tools that use an arduino and will communicate over uart-serial
  (i.e. with a single microcontroller attached. See i2c for talking to multiple arduinos or other boards).
  No changes should be necessary for connecting over USB vs hardware pins (remember to use a proper
  logic converter for connecting via pins).
  The main loop contains a call to checkSerial, and a switch statement against the received command. New commands
  should be defined within this switch statement. 
  This template is agnostic as to whether the data being sent is an int or a float. Both are available
  from the received bytes in the serialDataInt and serialDataFloat variables
*/

/* 
 *  This union facilitates conversion from a series of bytes to the 4-byte ints or floats they represent
 */
union byteConverter {
  byte asBytes[4];
  int asInt;
  float asFloat;
} converter;

/*
 * Contains the 1-byte command received from the serial message
 */
byte serialCommand = 0;

/*
 * Contains the 4-byte integer or float representation of the data from the serial message
 */
int serialDataInt = 0;
float serialDataFloat = 0;

/*
 * Keeps track of serial data as its received
 */
byte serialCount = 0;


/*
 * Example command. Commands are best described with #define for easy readability
 */
#define COMMAND_ON_OFF 0



void setup() {
  pinMode(13, OUTPUT); // Used with example command
  Serial.begin(9600);
}


void loop() {
  if (checkSerial()) {
    switch (serialCommand) {
      
      // Example command
      case COMMAND_ON_OFF:
        digitalWrite(13, serialDataInt);
        break;

        
        // === ADD CUSTOM TOOL COMMANDS HERE ===

        // === END CUSTOM CODE ===
    }
  }
}

/*
 * Receives bytes from the serial connection, and stores them in the converter union. 
 * Returns true if a full message of 5 bytes has just finished being received
 */
boolean checkSerial() {
  while (Serial.available() > 0) {
    if (serialCount == 0) {
      serialCommand = Serial.read();
    }
    else {
      converter.asBytes[serialCount - 1] = Serial.read();
    }

    if (serialCount == 4) {
      serialCount = 0;
      serialDataInt = converter.asInt;
      serialDataFloat = converter.asFloat;
      return true;
    }
    else {
      serialCount += 1;
    }
  }
  return false;
}
