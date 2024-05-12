import Adafruit_DHT
import requests
import time

'''
GET STARTED WITH THINGSPEAK IoT:

    Go To Thingspeak IoT and Login to your account
    Create a New Channel
    Use Two Fields for this Program
    and Save the Channel

    Replace your API Keys with below variables
'''

channel_id = <YOUR_THINGSPEAK_CHANNEL_ID>
read_key = <YOUR_THINGSPEAK_READ_KEY>
write_key = <YOUR_THINGSPEAK_WRITE_KEY>

pin = 4
sensor = Adafruit_DHT.DHT11

def measure(channel):
    try:
        humidity, temperature = Adafruit_DHT.read_retry(sensor,pin)
        print(humidity,temperature)
        if humidity is not None and temperature is not None:
            response = requests.post(
                "https://api.thingspeak.com/update",
                params = {
                    "api_key" : write_key
                },
                data={
                    "field1":temperature,
                    "field2":humidity
                }
            )
            print(response.text)

            read = requests.get(
                "https://api.thingspeak.com/channels/{}/feeds.json".format(channel_id),
                params = {
                    "api_key" : read_key
                },
            )
            print(read.json())
        else:
            print("Failed to Read")

    except Exception:
        print("Connection Failed")

if __name__ == "__main__":
    while True:
        measure(channel_id)
        time.sleep(5)