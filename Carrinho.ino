/*
  IFMS-CAR
*/

int ENA = 2;
int IN1 = 4; // Gira as rodas da direita para traz
int IN2 = 5; // Gira as rodas da direita para frente
int ENB = 3;
int IN3 = 6; // Gira as rodas da esquerda para traz
int IN4 = 7; // Gira as rodas da esquerda para frente
int tempo = 100; //Tempo de delay

// Inicializa os componentes do carrinho

void setup() {
  pinMode( 15, INPUT_PULLUP ); // fix Serial3
  Serial.begin(9600);

  pinMode(13, OUTPUT);

  digitalWrite(9, HIGH);

  Serial.println("Enter AT commands:");

  Serial3.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  Serial.begin(9600);
}

// Movimenta o carrinho para frente
void paraFrente() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(tempo);
}

// Movimenta o carrinho para traz
void paraTras() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(tempo);
}

// Movimenta o carrinho para esquerda
void paraEsquerda() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(tempo);


}

// Movimenta o carrinho para direita
void paraDireita() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(tempo);
}

// Para o carrinho
void parar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {

String t = "";
  if (Serial3.available()) {
    t += (char)Serial3.read();
    delay(10);
    Serial.println(t);
    delay(10);
  if (acao == 'F') { //Iniciar
    paraFrente();
    Serial.println("foi para frente");
  } else if (acao == 'T') { //Desligar, parar o carro
    paraTras();
  } else if (acao == 'D') { //Parar
    paraDireita();
  } else if (acao == 'E') { //Frente
    paraEsquerda();
  } else if (acao == 'P') { //Traz
    parar();
  }
} 
  if (Serial.available()) {
    Serial3.write(Serial.read());
  }
}
