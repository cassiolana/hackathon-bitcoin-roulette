//http://pt.scribd.com/doc/33640211/ArduinoLcdSensorIR#scribd
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int engine = 8;

int analogPin = A0;
int val = 0;
int v = 5;
int r1 = 10000;
int r2aux = 1000;

String inputString = "";
boolean stringComplete = false;
int loops = 1;
void setup() {
  Serial.begin(9600);
  inputString.reserve(200);
  
  pinMode(engine, OUTPUT);
  
  lcd.begin(16, 2);
  lcd.print("Posicao:  0");
}

void loop() {
  int result = readPosition();

  lcd.setCursor(10, 0);
  lcd.print("      ");
  lcd.setCursor(10, 0);
  lcd.print(result);
  Serial.println(result);
  
  
  if (stringComplete) {
    startEngine();

    delay(1000);

    lcd.setCursor(0, 1);
    lcd.print("            ");

    lcd.setCursor(0, 1);
    lcd.print(inputString);
    
    inputString = "";
    stringComplete = false;
  }

  lcd.setCursor(12, 1);  
  lcd.print(loops++);
  
  delay(1000);
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read(); 
    if (inChar == '\n') {
      stringComplete = true;
    } else {
      inputString += inChar;
    }
  }
}


int readPosition(){
  val = analogRead(analogPin);
  double vout = val * (5.0 / 1023);
  int r2 =  r1 * (1 / (v/vout - 1));
  int pos = r2/r2aux;
  int resto = r2 % r2aux;
  if (resto > 500) {
    pos = pos + 1;
  }
  return pos;
}

void startEngine() {
  digitalWrite(engine, HIGH);
  delay(3000);
  digitalWrite(engine, LOW);
}
