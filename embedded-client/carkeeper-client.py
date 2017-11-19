import serial #Import Serial Library
 
arduinoSerialData = serial.Serial('/COM5',9600) #Create Serial port object called arduinoSerialData

#from PIL import Image                                                                             
#img = Image.open('test.png')
#img.show()
#img = Image.open('test2.png')
#img.show()

#import os
#os.system('start test.png')
#os.system('taskkill test.png')

import webbrowser
webbrowser.open('Tela 1 CarKeeper.png')
 
while (True):
    if (arduinoSerialData.inWaiting()>0):
        myData = arduinoSerialData.readline()
        print(myData)
        if (myData == 'b\'{OilPlug,1}\\n\''):
            webbrowser.open('tampa_oleo_aberta.png')
        if (myData == 'b\'{OilPlug,0}\\n\''):
            webbrowser.open('tampa_oleo_fechada.png')
            
        if (myData == 'b\'{AirFilter,1}\\n\''):
            webbrowser.open('filtroAr_removido.png')
        if (myData == 'b\'{AirFilter,0}\\n\''):
            webbrowser.open('filtroAr_instalado.png')
            
        if (myData == 'b\'{OilReservoirScrewCap,1}\\n\''):
            webbrowser.open('Tela Filtro Ar removido.png')
        if (myData == 'b\'{OilReservoirScrewCap,0}\\n\''):
            webbrowser.open('bujao_fechado.png')
            
        if (myData == 'b\'{FuelFilter,1}\\n\''):
            webbrowser.open('fuelFilter_removido.png')
        if (myData == 'b\'{FuelFilter,0}\\n\''):
            webbrowser.open('fuelFilter_instalado.png')
            
        if (myData == 'b\'{OilFilter,1}\\n\''):
            webbrowser.open('oilFilter_removido.png')
        if (myData == 'b\'{OilFilter,0}\\n\''):
            webbrowser.open('oilFilter_instalado.png')
