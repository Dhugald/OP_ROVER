import sys
import PySimpleGUI as sg
import cv2
import time
# Send Action to Control Rover
def rover(action):
    if action == "UP":
        print('U') #Implement controls for the camera later
    if action == "LEFT":
        print('L') #Implement controls for the camera later
    if action == "RIGHT":
        print('R') #Implement controls for the camera later
    if action == "DOWN":
        print('D') #Implement controls for the camera later

# All the stuff inside your window.
font = "Ariel 32"
col =  [[sg.Text(" ",size=(20,1) , key="feedback")],
[sg.Button("UP", size=(5,1), font=font)],
[sg.Button("LEFT", size=(5,1), font=font),sg.Button("RIGHT", size=(5,1), font=font)],
[sg.Button("DOWN", size=(5,1), font=font)],
[sg.Button("QUIT")]
]
image=[[sg.Image(filename='', key='cam')]]

layout = [
    [sg.Column(image, element_justification='c', justification='c')],
    [sg.Column(col, element_justification='c', justification='c')]
]
# Create the Window
cap = cv2.VideoCapture(0)
window = sg.Window('PySimpleGUI Rover Control', layout, size=(1920, 1080), no_titlebar=False, alpha_channel=1, grab_anywhere=False, resizable=True)


# Event Loop to process "events" and pass them to the rover function

while True:
    start_time = time.time()
    event, values = window.read(timeout=20)
    print(event,values)
    if event in (None, 'QUIT'): # if user closes window or clicks cancel
        break
    if event != '__TIMEOUT__':
        window['feedback'].Update(event) # show the button in the feedback text
    ret, frame = cap.read()                               # Read image from capture device (camera)
    imgbytes=cv2.imencode('.png', frame)[1].tobytes()     # Convert the image to PNG Bytes
    window['cam'].update(data=imgbytes)   # Change the Image Element to show the new image
    rover(event)
    
cap.release()
window.close() # exit cleanly