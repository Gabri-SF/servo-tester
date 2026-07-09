const int servoPin = 0; // PB0
const int led1 = 3;     // PB3
const int led2 = 4;     // PB4
const int potPin = A1;  // PB2

volatile bool mode = 0;  // ALTERADO NA INTERRUPÇÃO

// -------------------------
// INTERRUPÇÃO BOTÃO (PB1)
// -------------------------
ISR(PCINT0_vect) {
  mode = !mode; // toggle simples e rápido
}

void setup() {
  pinMode(servoPin, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  pinMode(potPin, INPUT);

  // PB1 como input com pullup (botão para GND)
  pinMode(1, INPUT_PULLUP);

  // -------------------------
  // ATIVAR PIN CHANGE INTERRUPT NO PB1
  // -------------------------
  GIMSK |= (1 << PCIE);    // ativa PCINT
  PCMSK |= (1 << PCINT1);  // ativa interrupção no PB1
  sei();                   // ativa interrupções globais
}

void loop() {

  // -------------------------
  // MODO POTENCIÓMETRO
  // -------------------------
  if (mode == 0) {

    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);

    int potValue = analogRead(potPin);
    int pulse = map(potValue, 0, 1023, 500, 2400);

    digitalWrite(servoPin, HIGH);
    delayMicroseconds(pulse);
    digitalWrite(servoPin, LOW);
    delayMicroseconds(20000 - pulse);
  }

  // -------------------------
  // MODO AUTOMÁTICO
  // -------------------------
  else {

    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);

    // 0°
    for (int i = 0; i < 80; i++) {
      if (mode == 0) return; // sai imediatamente se mudar modo

      digitalWrite(servoPin, HIGH);
      delayMicroseconds(500);
      digitalWrite(servoPin, LOW);
      delayMicroseconds(19500);
    }

    // 180°
    for (int i = 0; i < 80; i++) {
      if (mode == 0) return;

      digitalWrite(servoPin, HIGH);
      delayMicroseconds(2400);
      digitalWrite(servoPin, LOW);
      delayMicroseconds(17600);
    }
  }
}
