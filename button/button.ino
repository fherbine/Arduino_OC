void  setup(void)
{
  pinMode(7, INPUT);
  Serial.begin(9600);
}

void  loop(void)
{
  boolean state = digitalRead(7);
  Serial.println(state);
}
