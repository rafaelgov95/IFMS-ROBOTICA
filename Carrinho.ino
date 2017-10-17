/*
 *   Autor: Rafael Viana
 *
 *  Evento: Semana da Ciência e Tecnologia - IFMS 2017
*/

int ENA = 2;
int IN1 = 4; 
int IN2 = 5; 
int ENB = 3;
int IN3 = 6;
int IN4 = 7; 
int tempo = 100; //Tempo de delay

// Inicializa os componentes do carrinho

void setup() {
  pinMode( 15, INPUT_PULLUP ); // fix Serial3
  digitalWrite(9, HIGH);
  Serial.println("Enter AT commands:");
  Serial.begin(9600);
  Serial3.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

}

// Movimenta o carrinho para frente
void paraFrente() {
  Serial.println("Frente");
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
  delay(tempo/2);


}

// Movimenta o carrinho para direita
void paraDireita() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(tempo/2);
}

// Para o carrinho
void parar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {
  String command = "";
  String t = "";
  if (Serial3.available()) {
    t = (char)Serial3.read();
    delay(10);
    Serial.println(t);
    delay(10);
    if (t.equals("F")) { //Frente
      paraFrente();
    } else if (t.equals( "T")) { //Trás
      paraTras();
    } else if (t.equals("D")) { //Direita
      paraDireita();
    } else if (t.equals("E")) { //Esquerda
      paraEsquerda();
    }
    parar();// Para o carrinho
  }
  /*
    Linha para configuração por comando AT.
  */
  //  if (Serial3.available()) {
  //    Serial.write((char)Serial3.read());
  //  }
  //  if (Serial.available()) {
  //    Serial3.write((char)Serial.read());
  //  }

}
