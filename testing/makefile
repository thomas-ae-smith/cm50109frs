CC=g++
CFLAGS=-c -Wall
OUT_O_DIR = obj/
all: frs

frs: controller_harness.o Controller.o Model.o CLIView.o Flight.o Passenger.o 
	$(CC) controller_harness.o Controller.o Model.o CLIView.o Flight.o Passenger.o -o frs

controller_harness.o: controller_harness.cpp
	$(CC) $(CFLAGS) controller_harness.cpp

Controller.o: ../Controller.cpp
	$(CC) $(CFLAGS) ../Controller.cpp

CLIView.o: ../CLIView.cpp
	$(CC) $(CFLAGS) ../CLIView.cpp

Model.o: ../Model.cpp
	$(CC) $(CFLAGS) ../Model.cpp

Flight.o: ../Flight.cpp
	$(CC) $(CFLAGS) ../Flight.cpp

Passenger.o: ../Passenger.cpp
	$(CC) $(CFLAGS) ../Passenger.cpp

clean:
	rm -rf *o obj/
