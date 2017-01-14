# Requirements

- 1 Raspberry Pi, raspbian installed, an IP address for your Raspberry Pi (use your dhcp server)
- 1 Arduino Uno
- a led strip: [buy this one from adafruit](https://www.adafruit.com/product/2842)
- a power supply for the led strip 5V / 2A
- some patience if you have a cat and even more if you have more than one
- a structure (3d printed or something else)

# Structure

I chose to use MDF since it's cheaper than 3d printing at this size.

### upper disc
- outer radius: 16.6 cm
- inner radius: 12.8 cm
- height: 0.3 cm

### main disc
- outer radius: 15.92 cm
- inner radius: 12.8 cm
- height: 1 cm

### lower disc
- outer radius: 18.2 cm
- inner radius: 14.4 cm
- height: 1 cm

# Wiring

The wiring may depend on the led strip that you chose. The [tutorial at Adafruit](https://learn.adafruit.com/adafruit-neopixel-uberguide/basic-connections) is good enough.

<img src="photos/leds_Wiring-Diagram.png">

# First test of the led strip connected to the Arduino

To check your wiring, use the arduino code located in the arduino/v0 folder.

Be sure to download the library for the Arduino here:
[Arduino Library Installation](https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-installation)

## Installation of the NeoPixel library
Recent versions of the Arduino IDE (1.6.2 and later) make library installation super easy via the Library Manager interface. From the Sketch menu, > Include Library > Manage Libraries...  In the text input box type in "NeoPixel". Look for "Adafruit NeoPixel by Adafruit" and select the latest version by clicking on the dropbox menu next to the Install button. Then click on the Install button. After it's installed, you can click the "close" button.

<img src="photos/leds_arduino-library-manager.png">

Upload the v0.ino to your Arduino connected to an usb port of your computer.

## Test

Plug:
- the wire of the data pin of the led strip to the pin number 6 of your Arduino
- the ground wire to one of the two ground pins of the Arduino
- your led strip to a 5V * 2A power supply.

You should see an animation. If not, check the wiring.

<img src="photos/IMG_20170112_223533.jpg">


# Build

## Wiring

We need to put the cables together in a tube.

Isolate the capacitor and the connector. Cut the cable and solder 3 long cables:
- one for power supply
- one for the ground
- one for data

Cut the cables and keep this apart:
<img src="photos/IMG_20170114_193142.jpg">

Solder each cable to their respective brother. Put some tape around your soldering to isolate them.
<img src="photos/IMG_20170114_194057.jpg">

Put the 3 long cables in a tube, like this one (you can do what you want, this is ugly I agree but it's temporary):

<img src="photos/IMG_20170114_194639.jpg">

## Power supply for the Arduino, the Raspberry Pi, and the led strip



# Installation of the web application

## Apache vhost config

Obviously you should modify these lines according to your Raspberry's configuration. I chose the port 80 that might already be in use. Check with your local BOFH for help.

```
<VirtualHost *:80>
        ServerAdmin webmaster@localhost
        DocumentRoot /var/www/ledclock/webapp/html

        <Directory /var/www/ledclock/webapp/html>
                AllowOverride All
        </Directory>
        
        ErrorLog ${APACHE_LOG_DIR}/error.log
        CustomLog ${APACHE_LOG_DIR}/access.log combined
</VirtualHost>
```

## Installation of the packages and the webapp
```
sudo apt-get install -y php5
sudo apt-get install -y git
sudo su -s /bin/bash www-data
cd /var/www
git clone https://github.com/jarnix/nofussframework.git
git clone https://github.com/jarnix/ledclock.git
sudo chown -R www-data.www-data ledclock
sudo a2enmod rewrite
sudo apt-get install -y php5-intl
sudo service apache2 restart
```

# Usage

http://<ip of your raspberry>

