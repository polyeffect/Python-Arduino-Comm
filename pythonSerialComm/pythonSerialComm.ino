int led = 13; // Digital Write LED pin: 13
int pwmLed1 = 11; // Analog Write LED pin ~11
int pwmLed2 = 3; // Analog Write LED pin ~3

String sX, sY; // X, Y coordinates String
int cX, cY; // X, Y coordinates int

byte incomingByte = 0;
String inputString = "";

boolean stringComplete = false;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.flush();
  
  inputString.reserve(200); // allocate buffer in memory
}

void loop() {
  if (stringComplete) {
    if (inputString.indexOf(',')) {
      int comma = inputString.indexOf(',');
      sX = inputString.substring(0, comma);
      sY = inputString.substring(comma + 1);
      cX = sX.toInt();
      cY = sY.toInt();

      analogWrite(pwmLed1, cX); //LED 1
      analogWrite(pwmLed2, cY); // LED 2

      //      if (cX == 192 && cY == 120) {
      //
      //      } else if (cX == 0 && cY == 0) {
      //
      //      }
    }

    if (inputString == "on") {
      digitalWrite(led, HIGH);
    } else if (inputString == "off") {
      digitalWrite(led, LOW);
    }

    Serial.println(inputString);
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {

    } else {
      inputString += inChar;
    }

    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

