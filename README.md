# Requirements

- 1 Raspberry Pi, raspbian installed, an IP address assigned to your Raspberry Pi on the wifi interface
- 1 Arduino Uno
- a led strip: [for example: this one from adafruit](https://www.adafruit.com/product/2842)
- a power supply for the led strip 5V / 2A, and the Arduino (5V / 1A), and the Raspberry Pi (also 5V / 1A), we will use just a single power supply (5V / 6A) for the actual build
- a 1000 µF capacitor and a 470 ohm resistor for the led strip
- a [cable](https://www.amazon.fr/gp/product/B003BZ00CE/ref=od_aui_detailpages01?ie=UTF8&psc=1) to connect your power supply to the grid 
- a structure (3d printed or something else like MDF) for attaching the led strip
- a box for putting the electronics inside (power supply + Arduino + Raspberry Pi), I chose [this box](http://www.creavea.com/coffre-en-bois-a-decorer-rectangulaire-165-cm_boutique-acheter-loisirs-creatifs_43684.html) to customize from a craft and hobbies site
- two small air fans [like these](https://www.amazon.fr/gp/product/B01M2YB9TV/ref=oh_aui_search_detailpage?ie=UTF8&psc=1) to evacuate the heat generated by the electronics
- a small usb cable to connect the Pi to the Arduino [like this one](https://www.seeedstudio.com/USB-Cable-Type-A-to-B-30CM-Black-p-1701.html)
- a Dremel to cut holes in the wood box

- some patience if you have a cat and even more if you have more than one

# Structure

I chose to use MDF since it's cheaper than 3d printing at this size.

### upper disc
- outer radius: 16.6 cm-
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

The discs look like this (with the led strip temporarily attached so you can understand):

<img src="photos/IMG_20170114_211917.jpg">

I will paint them and glue them together so the upper disc covers the side of the led strip (so we only see the light and not the ugly leds), and the main disc will be use for hanging it to the wall (and maybe a mod with translucent cubes to spread the light, that may come later).

<img src="photos/IMG_20170114_212006.jpg">

# Wiring

The wiring may depend on the led strip that you chose. The [tutorial at Adafruit](https://learn.adafruit.com/adafruit-neopixel-uberguide/basic-connections) is good enough.

You will need a 1000 µF capacitor and a 470 ohm resistor.

<img src="photos/leds_Wiring-Diagram.png">

# First test of the led strip connected to the Arduino

## Installation of the NeoPixel library

Please download the library for the Arduino for talking to the led strip here:
[Arduino Library Installation](https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-installation)

Recent versions of the Arduino IDE (1.6.2 and later) make library installation super easy via the Library Manager interface. From the Sketch menu, > Include Library > Manage Libraries...  In the text input box type in "NeoPixel". Look for "Adafruit NeoPixel by Adafruit" and select the latest version by clicking on the dropbox menu next to the Install button. Then click on the Install button. After it's installed, you can click the "close" button.

<img src="photos/leds_arduino-library-manager.png">

## Upload of the code

To check your wiring, we will use the example Arduino code located in the arduino/v0 folder.

Open the file arduino/v0/v0.ino with your Arduino IDE.

Upload the code to your Arduino connected to an usb port of your computer.

## Test

Plug:
- the wire of the data pin of the led strip to the pin number 6 of your Arduino
- the ground wire to one of the two ground pins of the Arduino
- your led strip to a 5V * 2A power supply.

You should see an animation. If not, check the wiring. The leds should do a animation like on this picture:

<img src="photos/IMG_20170112_223533.jpg">

# Build

## Wiring

We need to put the cables together in a tube to hide them and then plug all the things to a power source.

Isolate the cables connected to the led strip. Cut the cables and solder them with 3 other longer cables:
- one for power supply (red)
- one for the ground (a dark color)
- one for data (yellow, or white)

I used 2 meter cables, which should be enough excepted if you're a giant.

Cut the cables and keep this apart:
<img src="photos/IMG_20170114_193142.jpg">

Solder each cable to their respective brother. Put some tape around your soldering to isolate them.
<img src="photos/IMG_20170114_194057.jpg">

Put the 3 long cables in a tube, like this one (you can do what you want, this is ugly I agree but it's temporary):

<img src="photos/IMG_20170114_194639.jpg">

## Power supply for the Arduino, the Raspberry Pi, and the led strip

During this step, be *extremely careful* when dealing with power supply from your outlet. Do not drink alcohol while doing this.

Be also careful not to invert the cables since you can burn the components of your Arduino and/or Raspberry Pi.

We are going to use a single power supply for all of them.

### Raspberry Pi

The Raspberry Pi needs 5V. The power IN is the pin n°2 and the ground is the pin n°6 as you can see on this photo:

<img src="photos/IMG_20170114_205915.jpg">

### Arduino

The Arduino also needs 5V and has two pins named Vin for voltage IN and GND for ground:

<img src="photos/IMG_20170114_210738.jpg">

### Led strip

The led strip requires 5V and needs to be connected also, use the corresponding 2 cables from the 3 connected to the led strip, so: the red one and the dark/black one.

# Customizing the box

The box will need a small hole for the power supply cable, and two larger ones for the air fans. I chose to put one fan on the right and one on top of the box.

I used a Dremel, the first basic model will do, [like this one](https://www.amazon.fr/Dremel-3000-15-rotatif-multi-usage-accessoires/dp/B0073R1IZ4/ref=sr_1_1?s=hi&ie=UTF8&qid=1485027434&sr=1-1).

Cut the holes for the fans (at their exact shape) with a cutting disc, soften with sandpaper (use your Dremel again).

First hole for the power cord:

<img src="photos/IMG_20170121_201635.jpg">

Second and third hole for the fans:

<img src="photos/IMG_20170121_201612.jpg">

So the box should look like that:

<img src="photos/IMG_20170121_201828.jpg">

## Attaching the fans to the box

To attach the fans to the box, I drew this object in 3d:

<img src="photos/fastener.png">

You can [see it on Sketchfab](https://sketchfab.com/models/18709e0d36ae43969bd89f850368d4fc).

And printed it (~ 10 €):

# Putting all together

## Paint if you want

I painted the discs in black, painted the box in black and used a black cord around the cables connecting the Arduino to the led strip.

## Connect the Arduino to the power source

The box on this photo contains only the power source, a tiny breadboard, the arduino, and two small fans that are not connected yet.

<img src="IMG_20170408_000947.jpg">

## A preview of what it will be

<img src="IMG_20170408_001042.jpg">

## Connect the Pi to the power source

TODO

## Attaching the led strip to the main disc

Do not use glue, use double-sided adhesive tape, [like this one](https://www.amazon.fr/gp/product/B016UUOZBI/ref=oh_aui_search_detailpage?ie=UTF8&psc=1).

## 

---
TODO
---

# Installation of the web application

TODO

## Installation of the packages and the webapp

TODO

# Usage

TODO

