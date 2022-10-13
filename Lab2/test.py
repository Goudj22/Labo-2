import sys
#import keyboard
sys.path.append("C:/Users/fbgoudiaby/Downloads/Lab2 (1)/Lab2/Lab2/x64/Release")
import Lab2

Lab2.Play()

while True:

    print ("Choisissez une des option suivante\n"
           " p - Pause  \n"
           " e - Play   \n"
           " a - Avance accélérée\n"
           " r - Retour au début \n"
           " q - Quitter \n")

    choix = input()
    
    if (choix == 'p'):
        Lab2.Pause()

    elif (choix == 'e'):
        Lab2.Play()

    elif (choix == 'r'):
        Lab2.Restart()

    elif (choix == 'a'):
        Lab2.FastForward()

    elif (choix == 'q'):
        Lab2.Quitter()



#keyboard.on_press_key('p', lambda _: Lab2.Play())
##keyboard.on_press_key("r", lambda _: Lab2.Restart())
#keyboard.on_press_key('q', lambda _: Lab2.Quitter())

#Lab2.Play()


#keyboard.unhook_all()