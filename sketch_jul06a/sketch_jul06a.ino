int led = 13; // pin 13
int cX, cY;
byte incomingByte = 0;
String inputString = "";
String sX, sY;
boolean stringComplete = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  //  digitalWrite(led, HIGH);
  Serial.begin(9600);
  Serial.flush();
  inputString.reserve(200);
}

void loop() {
  if (stringComplete) {


    if (inputString.indexOf(',')) {
      int comma = inputString.indexOf(',');
      sX = inputString.substring(0, comma);
      sY = inputString.substring(comma + 1);
      cX = sX.toInt();
      cY = sY.toInt();

      if (cX == 192 && cY == 120) {
        digitalWrite(led, HIGH);
      } else if (cX == 0 && cY == 0) {
        digitalWrite(led, LOW);
      }
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

