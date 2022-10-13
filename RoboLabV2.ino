#include <Arduino.h>

// Declarando variaveis pros sensores (IR / LDR)
#define IRExtremoDireita A0   // Sensor extremidade direita
#define IREsquerda A1         // Sensor esquerda meio
#define IRExtremoEsquerda A2  // Sensor extremidade esquerda
#define IRDireita A3          // Sensor direita meio
#define LDR A5                // Sensor meio

// Declarando variaveis pros motores (IN1, IN2, IN3, IN4)
#define MDireita1 10  // Motor Direita (IN1)
#define MDireita2 11  // Motor Direita (IN2)
#define MEsquerda1 9  // Motor Esquerda (IN3)
#define MEsquerda2 6  // Motor Esquerda (IN4)

// Declarando variaveis para a velocidade dos motores
#define v1 90  // Velocidade Motor Direita
#define v2 90  // Velocidade Motor Esquerda

// Declarando variaveis para os valores 'branco' do sensor
#define pretoIR 1000  // Valor que o sensor IR detecta como branco
#define pretoLDR 750  // Valor que o LDR detecta como branco

// Variaveis que recebem a leitura dos sensores (Iniciam 0)
short SenED = 0;
short SenD = 0;
short SenM = 0;
short SenE = 0;
short SenEE = 0;

// Declarando as funções
void LerSensores();               // Faz a leitura dos sensores IR
void ImprimirValoresSensores();   // Imprime os valores dos sensores
void AndarFrente();               // Carro segue a linha
void AjeitarEsquerda();           // Ajeita o carro na linha reta
void AjeitarDireita();            // Ajeita o carro na linha reta
void CurvaEsquerda();             // Curva 90º para a esquerda
void CurvaDireita();              // Curva 90º para a direita
void DarPassoAFrente();           // Dar um passo a frente
void Parar();                     // Para o robô

void setup() {
  Serial.begin(9600);  // Iniciando o monitor serial (9600 baud)

  // Declarando o tipo dos pinos dos motores como OUTPUT
  pinMode(MDireita1, OUTPUT);
  pinMode(MDireita2, OUTPUT);
  pinMode(MEsquerda1, OUTPUT);
  pinMode(MEsquerda2, OUTPUT);
}

void loop() {
  LerSensores();
  ImprimirValoresSensores();

  // Sensor IR < brancoIR -> Sensor está no branco
  // LDR < brancoLDR -> Sensor está no branco

  // Andar para frente

  if (SenM < pretoLDR && SenEE >= 950 && SenED >= 950) {
    AndarFrente();
  } 
  else {
    if (SenD < 950 || SenED < 950) {
      AjeitarDireita();
    } 
    else if (SenE < 950 || SenEE < 950) {
      AjeitarEsquerda();
    }
  }
}

// Funções
void ImprimirValoresSensores() {
  Serial.print("ED: ");
  Serial.println(SenED);
  Serial.print("D: ");
  Serial.println(SenD);
  Serial.print("M: ");
  Serial.println(SenM);
  Serial.print("E: ");
  Serial.println(SenE);
  Serial.print("EE: ");
  Serial.println(SenEE);
  Serial.print("\n");
}

void LerSensores() {
  SenED = analogRead(IRExtremoDireita);   // Valores do sensor IR da extremidade direita
  SenD = analogRead(IRDireita);           // Valores do sensor IR da direita (próximo do meio)
  SenM = analogRead(LDR);                 // Valores do sensor LDR (sensor do meio)
  SenE = analogRead(IREsquerda);          // Valores do sensor IR da esquerda (próximo do meio)
  SenEE = analogRead(IRExtremoEsquerda);  // Valores do sensor IR da extremidade esquerda
}

void AndarFrente() {
  analogWrite(MDireita1, v1);
  analogWrite(MDireita2, 0);
  analogWrite(MEsquerda1, v2);
  analogWrite(MEsquerda2, 0);
}

void AjeitarEsquerda() {
  analogWrite(MDireita1, v1);
  analogWrite(MDireita2, 0);
  analogWrite(MEsquerda1, 0);
  analogWrite(MEsquerda2, 0);
}

void AjeitarDireita() {
  analogWrite(MDireita1, 0);
  analogWrite(MDireita2, 0);
  analogWrite(MEsquerda1, v2);
  analogWrite(MEsquerda2, 0);
}

void CurvaEsquerda() {
  DarPassoAFrente();
  analogWrite(MDireita1, v1);
  analogWrite(MDireita2, 0);
  analogWrite(MEsquerda1, 0);
  analogWrite(MEsquerda2, 0);
}

void CurvaDireita() {
  DarPassoAFrente();
  analogWrite(MDireita1, 0);
  analogWrite(MDireita2, 0);
  analogWrite(MEsquerda1, v2);
  analogWrite(MEsquerda2, 0);
}

void DarPassoAFrente() {
  AndarFrente();
  delay(100);
}

void Parar() {
  analogWrite(MDireita1, 0);
  analogWrite(MDireita2, 0);
  analogWrite(MEsquerda1, 0);
  analogWrite(MEsquerda2, 0);
}