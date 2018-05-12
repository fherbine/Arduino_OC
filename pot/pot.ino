const int led = 13;
int       a0_val = 0, bSpeed = 0, test = 0;

void setup(void)
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop(void)
{
  a0_val = analogRead(A0);
  // blinky_13(a0_val); // first led blinking test
  test = map(a0_val, 0, 1023, 1, 5);
  Serial.print(a0_val);
  Serial.print(" -> ");
  Serial.println(test);
  blinky2_13(test);
}

void blinky_13(int aValue)
{
    if (aValue > 400)
      bSpeed = 400;
    else
      bSpeed = (aValue < 100) ? 100 : aValue;

    do_blink(bSpeed);
}

void blinky2_13(int mapped_val)
{
  if (mapped_val == 1)
    bSpeed = 100;
  else if (mapped_val == 2)
    bSpeed = 200;
  else if (mapped_val == 3)
    bSpeed = 300;
  else if (mapped_val == 4)
    bSpeed = 400;
  else if (mapped_val == 5)
    bSpeed = 500;
    
  do_blink(bSpeed);
}

void  do_blink(int l13Speed)
{
  digitalWrite(led, HIGH);
  delay(l13Speed);
  digitalWrite(led, LOW);
  delay(l13Speed);
}
