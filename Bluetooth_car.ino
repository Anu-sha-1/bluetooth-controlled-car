int M11 = 4;
int M12 = 5;
int EN1 = 6;
int M21 = 9;
int M22 = 10;
int EN2 = 11;
char command;

void setup() {
  // put your setup code here, to run once:
  pinMode(M11, OUTPUT);
  pinMode(M12, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(M21, OUTPUT);
  pinMode(M22, OUTPUT);
  pinMode(EN2, OUTPUT);
  Serial.begin(9600);
  analogWrite(EN1, 150);
  analogWrite(EN2, 150);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0) {
    command = Serial.read();
    Serial.println(String(char(command)));
    switch(command) {
      case 'F': move_Forward();
      break;
      case 'B': move_Backward();
      break;
      case 'L': turn_Left();
      break;
      case 'R': turn_Right();
      break;
      case 'S': Stop();
      break;
    }
  }
}

void move_Forward() {
  digitalWrite(M11, HIGH);
  digitalWrite(M12, LOW);
  digitalWrite(M21, HIGH);
  digitalWrite(M22, LOW);
}
void move_Backward() {
  digitalWrite(M11, LOW);
  digitalWrite(M12, HIGH);
  digitalWrite(M21, LOW);
  digitalWrite(M22, HIGH);
}
void turn_Left() {
  digitalWrite(M11, HIGH);
  digitalWrite(M12, LOW);
  digitalWrite(M21, LOW);
  digitalWrite(M22, HIGH);
}
void turn_Right() {
  digitalWrite(M11, LOW);
  digitalWrite(M12, HIGH);
  digitalWrite(M21, HIGH);
  digitalWrite(M22, LOW);
}
void Stop() {
  digitalWrite(M11, LOW);
  digitalWrite(M12, LOW);
  digitalWrite(M21, LOW);
  digitalWrite(M22, LOW);
}