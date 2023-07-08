CC = g++
CFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SOURCES := main.cpp src/private/Game.cpp src/private/actors/Player.cpp src/private/actors/Bullet.cpp

#compile by copilot
all:
	$(CC) -o spaceship $(SOURCES) $(CFLAGS)

