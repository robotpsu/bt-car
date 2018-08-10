#define L1 2
#define L2 3
#define R1 4
#define R2 5
#define PL 9
#define PR 10
#define echoPin 12
#define trigPin 13
#define Laser 7
#define BT 11
#define Red A0
#define Gre A1

int t_signal = 5;
int t_delay = 100;
String st = "";

void setup() {
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(Laser, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Gre, OUTPUT); 
  pinMode(BT, OUTPUT);
  Serial.begin(9600);
}

void Forward() {
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
}

void Back() {
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH);
}

void Stop() {
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
}

void Turn(int angle) {
  if (angle > 0) {
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
    digitalWrite(R1, LOW);
    digitalWrite(R2, HIGH);
  } else {
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
  };
  delay(abs(angle*22));
  Stop();
}

void Left() {
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
}

void Right() {
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
    digitalWrite(R1, LOW);
    digitalWrite(R2, HIGH);
}

void Power(float p) {
  analogWrite(PL, p * 1024);
  analogWrite(PR, p * 1024);
}

void Laser_ON() {
  digitalWrite(Laser, HIGH);
}

void Laser_OFF() {
  digitalWrite(Laser, LOW);
}

void Fire(int Fire_t) {
    Laser_ON();
    delay(Fire_t);
    Laser_OFF();
}

void loop() {
  char c;
  while(Serial.available()) {
    c = Serial.read();
    Serial.println(c);
    st += c;
    delay(3);
  };
  switch(c) {
    case '8': Forward();
    break;
    case '6': Right();
    break;
    case '4': Left();
    break;
    case '2': Back();
    break;
    case '5': Fire(t_signal);
    break;
    case '0': Stop();
    break;
  }
  c = 0;
}
