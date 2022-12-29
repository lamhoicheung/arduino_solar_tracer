void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial)

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int darkness1 = analogRead(A0);
  int darkness2 = analogRead(A1);

  Serial.print(darkness1); Serial.print('\t');
  Serial.print(darkness2); Serial.println();

  delay(100);
}
