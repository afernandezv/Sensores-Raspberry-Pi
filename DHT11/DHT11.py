# Librerías necesarias adafruit-circuitpython-dht y libgpiod2
#
# Instalación
# sudo pip3 install adafruit-circuitpython-dht
# sudo apt-get install libgpiod2

import time
import board
import adafruit_dht

dhtDevice = adafruit_dht.DHT11(board.D4)

while True:
    try:
        temperature = dhtDevice.temperature
        humidity = dhtDevice.humidity
        print("Temperatura: {:.1f} C    Humedad: {}% ".format(temperature, humidity))
    except RuntimeError as error:
        print(error.args[0])
        time.sleep(2)
        continue
    except Exception as error:
        dhtDevice.exit()
        raise error
    time.sleep(2)
