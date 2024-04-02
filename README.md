An early form of simulated recoil. In the regular GUN4IR system, simulated recoil was done via the chip on the gun itself.
The idea here was to seperate recoil off of the chip's code and make the computer run it based off of what input
the computer picks up. Namely, using either the left mouse button or the 'Z' key, which should be easy to change.

I ended up dropping the idea in the final GUN4IR built, as this introduces about two more wires, which makes
the system less user friendly.

The optimal simulated recoil system would be decided per each game by the game, but that introduces a lot of variables, 
and so the idea is only ideal if you were to have something like a dedicated arcade cabinet.

HOW TO USE

Use the BOTHREGULAR.bat or the BOTHSWAPPED.bat to run their respective python scripts, they should be kept open while running. 
Take an arduino chip and upload the BOTHFIREAS.ino code to run, and keep it plugged into the computer. 
I used an arduino UNO, but I'm sure any of them would work. The arduino's 7 and 8 pins control the flow
of a powersource. Transistors are cheaper but difficult to use, but I was using a relay at the time which is simpler.
Also, you must make sure that the COM port in the .py codes correspond to what the arduino chip uses. There are a few ways to find out,
but I found mine in the arduino IDE by hitting 'tools' at the top menu bar, and it shows the port there.

TESTING/USE

Hitting the left mouse button or Z key makes the solenoiids fire, either autofire or singlefire.
Hitting the X key switches between single and autofire. Make sure that the solenoids are never 'stuck'
in an on position, as solenoids heat up when on for longer than a few seconds.

MODIFICATIONS

For more rapid fire or heat control, you can mess with the delay() function in the BOTHFIREAS.ino file.
For the previously mentioned game controlled recoil, you can have the game send 1, 2, 3, or 4 to the COM port
of the arduino.

TROUBLESHOOTING

Q. I got the following, what happened?
"Press any key to continue . . . Traceback (most recent call last):
  File "C:\Users\maste\Desktop\RECOIL\bothfire.py", line 6, in <module>
    arduino = serial.Serial('COM3', 9600, timeout=.1)
              ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "C:\Python311\Lib\site-packages\serial\serialwin32.py", line 33, in __init__
    super(Serial, self).__init__(*args, **kwargs)
  File "C:\Python311\Lib\site-packages\serial\serialutil.py", line 244, in __init__
    self.open()
  File "C:\Python311\Lib\site-packages\serial\serialwin32.py", line 64, in open
    raise SerialException("could not open port {!r}: {!r}".format(self.portstr, ctypes.WinError()))
serial.serialutil.SerialException: could not open port 'COM3': FileNotFoundError(2, 'The system cannot find the file specified.', None, 2)"

A. This means that you do not have the correct COM port for your arduino. Either edit the .py code to use the correct port, or make your arduino use COM port 3.


Q. Solenoid works, but after repeated use, gets stuck in the ON position.

A. First, immediately unplug the system, never let the solenoid get hot.
This is likely caused by not using a flyback diode, it protects the relay or transmitter or whatever is controlling your powersource.


Q. My computer doesn't like the .bat file, it blocks it from running.

A. This file does not edit files in any way, it is completely safe. Either run it with administrator priveleges or put it on an 'allowed list' on your antivirus.

Q. Does this support non GUN4IR systems like the synden lightgun?

A. As long as it sends a mouseclick or a keypress, it is supported. If you wanted to use more than one, then they cannot share the same output button. For instance, you can use a gun that uses a mouseclick for the trigger, but it wouldn't support a second gun with the mouseclick. However, if it were hooked up to the rightmouse click or the z key, it would work.

Q. What power source should I use?

A. Any amount of volts will work for this system, just make sure that your solenoid is rated for it and all your components can handle it and are safe.
