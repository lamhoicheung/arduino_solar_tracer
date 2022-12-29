#include <Servo.h>

Servo servo;
int pos = 90;

int threshold = 50;
int change_of_pos = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial)

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  servo.attach(6);
  servo.write(pos);
}

void loop() {
  // put your main code here, to run repeatedly:
  int darkness1 = analogRead(A0);
  int darkness2 = analogRead(A1);

  Serial.print(darkness1); Serial.print('\t');
  Serial.print(darkness2); Serial.println();

  int darkness_difference = darkness1 - darkness2;

  if (darkness_difference > threshold) pos -= change_of_pos;
  else if (darkness_difference < -threshold) pos += change_of_pos;

  pos = constrain(pos, 55, 125);

  servo.write(pos);

  delay(100);
}
