int ledpin = 9;
int switch_button = 7;
int incre_button = 11;
int decre_button = 12;
int buzzpin = 13;

int ledstate = 0;
int oldstate = 0;
int newstate = 0;
int incre_state = 0;
int decre_state = 0;

int brightness = 0;
int delay_time = 500;
int buzz_delay = 1000;

void setup() {
  // put your setup code here, to run once:
pinMode(ledpin, OUTPUT);
pinMode(switch_button, INPUT);
pinMode(incre_button, INPUT);
pinMode(decre_button, INPUT);
pinMode(buzzpin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

newstate = digitalRead(switch_button);
incre_state = digitalRead(incre_button);
decre_state = digitalRead(decre_button);


Serial.print("newstate is: \t");
Serial.print(newstate);
Serial.print(" ledstate is: \t");
Serial.print(ledstate);
Serial.print(" incre_state is: \t");
Serial.print(incre_state);
Serial.print(" Decre_state is: \t");
Serial.println(decre_state);


//delay(delay_time);
if(newstate == 1 && oldstate == 0){
  if(ledstate == 0){
    ledstate = 1;
    digitalWrite(ledpin, ledstate);
  }
  else if(ledstate == 1){
    ledstate = 0;
    digitalWrite(ledpin, ledstate);
  }
  
}
oldstate = newstate;


if(incre_state == 1){
  if(ledstate == 1){
    digitalWrite(buzzpin, HIGH);
    delay(buzz_delay);
    digitalWrite(buzzpin, LOW);
    brightness = 250;
    analogWrite(ledpin, brightness);
  } else {
  brightness = brightness + 25;
  analogWrite(ledpin, brightness);
  if(brightness > 250){
    digitalWrite(buzzpin, HIGH);
    delay(buzz_delay);
    digitalWrite(buzzpin, LOW);
    brightness = 250;
    analogWrite(ledpin, brightness);
    brightness = 250;
  }
  }
}


if(decre_state == 1){
  if(ledstate == 0 && brightness == 0){
    digitalWrite(buzzpin, HIGH);
    delay(buzz_delay);
    digitalWrite(buzzpin, LOW);
    brightness = 0;
    digitalWrite(ledpin, LOW);
  } else {
  //brightness = 250;
  brightness = brightness - 25;
  analogWrite(ledpin, brightness);
  if(brightness < 0){
    digitalWrite(buzzpin, HIGH);
    delay(buzz_delay);
    digitalWrite(buzzpin, LOW);
    brightness = 0;
    analogWrite(ledpin, brightness);

  }
  }
}


}

