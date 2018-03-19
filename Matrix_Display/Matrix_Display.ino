//sending values from an array using bit transfer method
byte A[] = {0x06, 0x09, 0x0F, 0x09, 0x09};
byte B[] = {0x0E, 0x09, 0x0E, 0x09, 0x0E};
byte C[] = {0x07, 0x08, 0x08, 0x08, 0x07};
byte d[3][5] = {A, B, C};
int clk = 2;
int data = 3;
int latch = 4;
int clkc = 5;
int reset = 6;
byte mask = 1;
void setup() {
  pinMode(clk, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(clkc, OUTPUT);
  pinMode(reset, OUTPUT);
  digitalWrite(clk, HIGH);
  digitalWrite(clkc, LOW);
  digitalWrite(reset, HIGH);
  digitalWrite(reset, LOW);
  Serial.begin(9600);
}
void dt(int j, byte x[]) {
  for (mask = 10000000; mask > 0; mask >>= 1) {
    if (x[j] & mask) {
      digitalWrite(clk, LOW);
      digitalWrite(data, HIGH);
      digitalWrite(clk, HIGH);
    }
    else {
      digitalWrite(clk, LOW);
      digitalWrite(data, LOW);
      digitalWrite(clk, HIGH);
    }
  }
}
void loop() {
  for (int k = 0; k < 3; k++) {
    d[k][];
    for (int j = 0; j < 100; j++) {
      digitalWrite(reset, HIGH);
      digitalWrite(latch, LOW);
      dt(0, d[k][]);
      digitalWrite(latch, HIGH);
      for (int i = 1; i < 6; i++) {
        digitalWrite(reset, LOW);
        digitalWrite(latch, LOW);
        dt(i, d[k][]);
        digitalWrite(latch, HIGH);
        digitalWrite(clkc, HIGH);
        digitalWrite(clkc, LOW);
      }
      delay(25);
    }
  }
}
