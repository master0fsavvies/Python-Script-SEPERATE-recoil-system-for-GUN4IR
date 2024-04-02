from pynput.keyboard import Key, Listener, KeyCode
from pynput.mouse import Button, Listener as MouseListener, Controller as MouseController
import serial
import signal

arduino = serial.Serial('COM3', 9600, timeout=.1)
mouse_listener = None
keyboard_listener = None
pressed_z = False
pressed_mouse = False

def signal_handler(signal, frame):
    print("Interrupted")
    if mouse_listener:
        mouse_listener.stop()
    if keyboard_listener:
        keyboard_listener.stop()

def on_press(key):
    global pressed_z
    
    if key == KeyCode.from_char('z'):
        if not pressed_z:
            pressed_z = True
            arduino.write(bytes("3", 'utf-8'))
    if key == KeyCode.from_char('x'):
        if not pressed_z:
            pressed_z = True
            arduino.write(bytes("5", 'utf-8'))

def on_release(key):
    global pressed_z
    
    if key == KeyCode.from_char('z'):
        if pressed_z:
            pressed_z = False
            arduino.write(bytes("4", 'utf-8'))
    if key == KeyCode.from_char('x'):
        if pressed_z:
            pressed_z = False
            arduino.write(bytes("6", 'utf-8'))

def on_click(x, y, button, pressed):
    global pressed_mouse
    
    if button == Button.left:
        if pressed:
            pressed_mouse = True
            arduino.write(bytes("1", 'utf-8'))
        else:
            pressed_mouse = False
            arduino.write(bytes("2", 'utf-8'))


signal.signal(signal.SIGINT, signal_handler)

mouse_listener = MouseListener(on_click=on_click)
mouse_listener.start()

keyboard_listener = Listener(on_press=on_press, on_release=on_release)
keyboard_listener.start()

mouse_listener.join()
keyboard_listener.join()
