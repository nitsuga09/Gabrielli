#ifndef _BOTON_h         //Si no esta definido

#define _BOTON_h         //defino boton.h

#include <Arduino.h>

class boton{
    public:
        boton(byte pin);
        void Refresh();
        PressTypes GetPressType();
        long startDebouncingMillis;
    
        enum PressTypes{
                NoPress;
                Press;
            }

    private:
        byte _pin;
        int debounceTimeMs;           //Tiempo de rebote
        PressTypes Presstype;

        enum State{
            Idle;                       //Espero a que el boton se presione
            FirstPress;                 //Primera vez que se presiona el boton
            DebouncingPress;            //Tiempo de rebote
            BotonPress;                 //Boton presionado
        }
        State state;
}

#endif                  //Tengo que cerrarlo
