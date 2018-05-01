void  setup(void)
{
  pinMode(13, OUTPUT);
}

void  loop(void)
{
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
}
