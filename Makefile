led-test: rpi_dma_utils.o rpi_pixleds_lib.o main.o
	gcc -o led-test rpi_dma_utils.o rpi_pixleds_lib.o main.o

rpi_dma_utils.o: rpi_dma_utils.c rpi_dma_utils.h
	gcc -c rpi_dma_utils.c

rpi_pixleds_lib.o: rpi_pixleds_lib.c rpi_pixleds_lib.h
	gcc -c rpi_pixleds_lib.c

rpi_pixleds.o: rpi_pixleds.c
	gcc -c rpi_pixleds.c

main.o: main.c
	gcc -c main.c

clean:
	rm -f *.o led-test
