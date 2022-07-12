#include <Arduino.h>
#include <SimpleDHT.h> //Biblioteca referente ao DHT22
#include "displayESP32LoRa.h" //Arquivo com as funções referentes ao display lora
#include "MQTT_Client.h" //Arquivo com as funções de mqtt

float temperature; //Temperatura que será obtida pelo sensor DHT
float humidity; //Umidade que será obtida pelo sensor DHT

const int pinDHT = 22; //Pino que é ligado no sensor DHT
SimpleDHT22 dht22(pinDHT); //Objeto que possui os métodos de leitura dos valores do sensor DHT

void setup() 
{
  //Para debug, iniciamos a comunicação serial com 115200 bps
  Serial.begin(115200);

  //Inicializa display lora
  if(!loraDisplayConfig())
    ESP.restart();

  //Exibe mensagem no display
  showDisplay(0, "Setting up mqtt...", true);
  Serial.println("Setting up mqtt...");

  //Inicializa mqtt (conecta o esp com o wifi, configura e conecta com o servidor da ubidots)
  if(!mqttInit())
  {        
    delay(3000);
    showDisplay(0, "Failed!", false);
    Serial.println("Failed!");
    ESP.restart();
  }
  showDisplay(0, "OK", false);
  Serial.println("OK");
}

//Obtém temperatura e umidade do sensor
bool getClimate()
{  
  int err = SimpleDHTErrSuccess;

  //Passamos as variáveis 'temperature' e 'humidity' por parâmetro na função chamada 'read2', elas serão retornadas por referência
  //Se não for retornado o código de SimpleDHTErrSuccess (sucesso), exibimos o valor de erro obtido
  if ((err = dht22.read2(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) 
  {
    Serial.print("Read DHT22 failed, err=");
    Serial.println(err);

    //Zera valores
    temperature = humidity = 0;
    return false;
  }

  return true;
}

//Essa função exibe os valores com suas respectivas unidades de medida para caso a flag 'success' seja true
//Caso a flag 'success' seja false, exibimos apenas um traço '-'
void showClimate(bool success)
{
  if(success)
  {
    showDisplay(0, "Temperature: "+String(temperature)+" °C", true);
    showDisplay(1, "Humidity: "+String(humidity)+" %", false);
    Serial.println("Temperature: "+String(temperature)+" °C");
    Serial.println("Humidity: "+String(humidity)+" %");
  }
  else
  {
    showDisplay(0, "Temperature: -", true);
    showDisplay(1, "Humidity: -", false);
    Serial.println("Temperature: -");
    Serial.println("Humidity: -");
  }
}

void loop() 
{
  //Se o esp foi desconectado do ubidots, tentamos reconectar
  if(!client.connected())
    reconnect();
  
  //Lê a temperatura e umidade e exibimos no display passando uma flag (que sinaliza sucesso na leitura)
  if(getClimate())
    showClimate(true);
  else
    showClimate(false);

  //Esperamos 2.5s antes de exibir o status do envio para dar efeito de pisca no display
  delay(2500);  
  if(sendValues(temperature, humidity))
  {      
    Serial.println("Successfully sent data");
    showDisplay(4,"Successfully sent data", false);
  }
  else
  {      
    Serial.println("Failed to send sensor data");
    showDisplay(4,"Failed to send sensor data", false);
  }    
    
  //Esperamos 2.5s para dar tempo de ler as mensagens acima
  delay(2500);    
}








