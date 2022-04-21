# multicore_pico
Multicore Pico. Programmed on two ARM M-profile RP2040 cores simultaneously to blink the LED and enabled communication via FIFO pipes between the two processors.


#Build

`mkdir build`

`cd build`

`cmake ..`

`make`

You will get your blind.uf2 file, copy it to pico storage. 
