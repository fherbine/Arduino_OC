void  setup(void)
{
  pinMode(7, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  digitalWrite(13, LOW);
}

void  loop(void)
{
  boolean state = digitalRead(7);
  if (state == 1)
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
  Serial.println(state);
}
