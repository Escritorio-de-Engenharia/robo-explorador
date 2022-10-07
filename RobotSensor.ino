#include <Arduino.h>
#include <ArxContainer.h>

short int psDireita = A0;
short int psMeio = A1;
short int psEsquerda = A2;

short cont = 0;

#define IN1 11
#define IN2 10
#define IN3 9
#define IN4 8

short velocidade = 100;

unsigned long tempoAtual;
unsigned long tempoAnterior = millis();

//using arx::vector;

//vector<char> dir;

void setup() {
  Serial.begin(9600);

  pinMode(psDireita, INPUT);
  pinMode(psMeio, INPUT);
  pinMode(psEsquerda, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void AndaPraFrente() {
  analogWrite(IN1, LOW);
  analogWrite(IN2, velocidade);
  analogWrite(IN3, velocidade);
  analogWrite(IN4, LOW);
  cont = 0;
  //Serial.println("Frente");
}

void Parar() {
   analogWrite(IN1, LOW);
   analogWrite(IN2, LOW);
   analogWrite(IN3, LOW);
   analogWrite(IN4, LOW);
}

void DarRe() {
  if(cont == 1){
    analogWrite(IN1, LOW);
    analogWrite(IN2, velocidade);
    analogWrite(IN3, LOW);
    analogWrite(IN4, velocidade);
  }
  if(cont == 2){
    analogWrite(IN1, velocidade);
    analogWrite(IN2, LOW);
    analogWrite(IN3, velocidade);
    analogWrite(IN4, LOW);
  }
}

void VirarEsquerda() {
  analogWrite(IN1, LOW);
  analogWrite(IN2, velocidade);
  analogWrite(IN3, LOW);
  analogWrite(IN4, LOW);
  cont = 1;
  Serial.println("Esquerda");
}

void VirarDireita() {
  analogWrite(IN1, LOW);
  analogWrite(IN2, LOW);
  analogWrite(IN3, velocidade);
  analogWrite(IN4, LOW);
  cont = 2;
  Serial.println("Direita");
}

void loop() {
  tempoAtual = millis();
  
  short pinoSensorDireita = analogRead(psDireita);
  short pinoSensorMeio = analogRead(psMeio);
  short pinoSensorEsquerda = analogRead(psEsquerda);

  // Menor que 980 o Sensor IR está no branco
  if(pinoSensorMeio < 999) // Verificar se o carro esta na linha
  {
    Serial.print("Meio: ");
    Serial.println(pinoSensorMeio);
    // Menor que 980 está no branco e numa intersecção T
    if(pinoSensorEsquerda < 980 && pinoSensorDireita < 980) // Intersecção T
    {
      VirarEsquerda();
    }
    else if(pinoSensorEsquerda < 980) // Virar a esquerda
    {
      unsigned long diferenca = tempoAtual - tempoAnterior;
      Serial.println(diferenca);
      VirarEsquerda();
    }
    else if(pinoSensorDireita < 980) // Virar a Direita
    {
      unsigned long diferenca = tempoAtual - tempoAnterior;
      Serial.println(diferenca);
      VirarDireita();
    }
    else
    {
      AndaPraFrente();
      tempoAnterior = tempoAtual;
    }
  }
  else // Se estiver no preto, ele para e dá uma ré
  {
    if(cont == 0){
      Parar();
    }
    else{
      DarRe();
    }
    
    //delay(500);
    Serial.println("parou");
  }

}
