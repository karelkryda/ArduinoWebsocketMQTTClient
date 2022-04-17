#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <PubSubClient.h>
#include "WebSocketStreamClient.h"

// WiFI
const char *ssid = "your_ssid";
const char *password = "your_password";

// MQTT Broker
const char *clientID = "unique_mqtt_client_id";
const char *topic = "test/topic";
const char *mqtt_server = "broker.mqttdashboard.com";
const int mqtt_port = 8000;
const char *mqtt_path = (char *)"/mqtt";

WiFiClientSecure client;
WebSocketClient wsClient(client, mqtt_server, mqtt_port);
WebSocketStreamClient wsStreamClient(wsClient, mqtt_path);
PubSubClient mqttClient(wsStreamClient);

void setup()
{
    Serial.begin(115200);

    WiFi.begin(ssid, password);
    Serial.println("Connecting");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());

    client.setInsecure();

    mqttClient.setCallback(MQTTcallback);
    Serial.println("Connecting to MQTT Broker");
    if (mqttClient.connect(clientID)) // for authorization use: mqttClient.connect(clientID, "username", "password")
    {
        Serial.println("Connected to MQTT Broker");

        mqttClient.subscribe(topic);
    }
    else
        Serial.println("Failed to connect to MQTT Broker");
}

void loop()
{
    if (!mqttClient.connected())
        reconnectMQTT();

    mqttClient.loop();
}

void reconnectMQTT()
{
    while (!mqttClient.connected())
    {
        Serial.print("Attempting MQTT connection...");

        if (mqttClient.connect(clientID)) // for authorization use: mqttClient.connect(clientID, "username", "password")
        {
            Serial.println("Reconnected to the MQTT Broker");

            mqttClient.subscribe(topic);
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(mqttClient.state());
            Serial.println(" try again in 5 seconds");

            delay(5000);
        }
    }
}

void MQTTcallback(char *topic, byte *payload, unsigned int length)
{
    Serial.print("Payload: ");
    for (int i = 0; i < length; i++)
        Serial.print((char)payload[i]);

    Serial.println();
}