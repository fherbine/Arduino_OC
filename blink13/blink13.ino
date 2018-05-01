void  setup(void)
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void  loop(void)
{
  digitalWrite(13, HIGH);
  Serial.println("State HIGH");
  delay(500);
  digitalWrite(13, LOW);
  Serial.println("State LOW");
  delay(500);
}
