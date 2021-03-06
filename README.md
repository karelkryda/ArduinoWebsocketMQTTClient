# ArduinoWebsocketMQTTClient

This repository contains all the necessary libraries for connecting to the MQTT broker using PubSubClient via Websocket.

This repository unifies the code from several libraries and their forks on GitHub, and thanks to this you can quickly establish a connection to the MQTT broker via Websocket without having to search and modify all the necessary libraries.

## Dependencies

- [WebSocketStreamClient](https://github.com/karelkryda/ArduinoWebsocketMQTTClient/tree/main/WebSocketStreamClient) - Forked from areve's [repository](https://github.com/areve/WebSocketStreamClient)
- [ArduinoHttpClient](https://github.com/karelkryda/ArduinoWebsocketMQTTClient/tree/main/ArduinoHttpClient) - Forked from arduino-libraries's [repository](https://github.com/arduino-libraries/ArduinoHttpClient)
- [arduinoWebSockets](https://github.com/Links2004/arduinoWebSockets)
- [PubSubClient](https://github.com/knolleary/pubsubclient)

## How to setup

This library contains everything needed to establish a connection to the MQTT broker using a web socket. All you need to do is the following:
 - Download the code from this repository
 - Copy the modified WebSocketStreamClient library from the corresponding folder to the `Your PC/Documents/Arduino/libraries` folder
 - Copy the modified ArduinoHttpClient library from the corresponding folder to the `Your PC/Documents/Arduino/libraries` folder
 - From the library manager in the Arduino IDE (`Sketch` menu > `Include Library` > `Manage Libraries`), install the **WebSockets** library by **Markus Sattler**, or download the code from [this repository](https://github.com/Links2004/arduinoWebSockets) and copy it to the Arduino libraries folder on your computer (the procedure is the same as in previous 2 steps)
 - Upload the sample code from the `examples` folder to the board

## Usage

You can see how to set up a connection in the example file [here](https://github.com/karelkryda/ArduinoWebsocketMQTTClient/tree/main/examples/mqtt-ws-client.ino).

## Credit

[clysss](https://github.com/clysss) - Made edits to the WebSocketStreamClient library - in [this repository](https://github.com/clysss/WebSocketStreamClient)

[emsi](https://github.com/emsi) - Added protocol support to WebSocketClient - in [this repository](https://github.com/emsi/ArduinoHttpClient)

[emsi](https://github.com/emsi) - Set protocol to mqtt (required by mosquitto) - in [this repository](https://github.com/emsi/WebSocketStreamClient)