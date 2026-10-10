Digispark ATtiny85 ATtinyPlexer
The Digispark ATtiny85 is a highly capable portable device that excels at emulating mice and keyboards for automation tasks. However, it is constrained by its limited I/O when attempting to control the program or select a different program.

This HAT connects to the microcontroller via pogo pins, enabling the user to choose one of 15 different signal combinations to control or select a program. It features two sliding control surfaces that bridge a combination of four pins. Pressing the button bridges them to ground, activating the signal.

The board includes two control surfaces that can be broken off the main PCB to bridge the contacts. 3D-printable enclosure files will be provided as soon as they are completed.

How to Use
Fabricate the PCBs: A hard gold surface finish is recommended for the top pads to ensure maximum longevity. Break off the sliding pads.

Assembly: Populate the board with the resistors and the switch. Solder the pogo pins to the ATtiny85 board.

Enclosure: 3D print the enclosure and place the PCBs inside (Files coming soon).

Software: Flash the microcontroller with the included Arduino project and integrate your custom code.

Pinout & Technical Details
Pins 0 and 2 utilize the standard internal pull-up resistors.

Pin 1 has an LED hardwired to the internal resistor and therefore requires an external pull-up resistor instead.

Pins 3 and 4 are reserved for USB communication.

Pin 5 is tied to the reset line by default, which activates when a low signal is detected.

By creating a voltage divider with the internal pull-up and an external resistor, one can use the analog read function to measure a slight voltage drop without reaching the low-voltage signal trigger point.

R5: The internal pull-up resistor on Pin 5 is rated between 30kΩ and 60kΩ. By choosing a 220kΩ external resistor, the voltage will never drop below the threshold required even in the worst spec case.

5V * (220k / (220k + 60k)) = 3.92V

The top sliding mechanism determines which pads get connected to ground using a binary system. When the user presses the button, the selected pads are shorted to ground, and the microcontroller registers the input.

BOM (Bill of Materials)
1x 1kΩ 1206 SMD generic resistor (5%)

1x 220kΩ 1206 SMD generic resistor (5%)

1x Würth Elektronik 434331045822 SMD side switch
