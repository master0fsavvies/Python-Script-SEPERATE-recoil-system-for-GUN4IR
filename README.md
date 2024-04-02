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
