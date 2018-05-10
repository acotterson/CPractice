###############################################################
# Program:
#     Milestone 08, Skeet
#     Brother Falin, CS165
# Author:
#     Alec Otterson
# Summary:
#     Make birds and bullets appear. 
# Above and Beyond
#     I added a faster hummingBird (worth more) and levels at certain point
#     intervals that make all birds faster.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o flyingObject.o bird.o bullet.o velocity.o standardBird.o sacredBird.o toughBird.o hummingBird.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o rifle.o flyingObject.o bird.o bullet.o velocity.o standardBird.o sacredBird.o toughBird.o hummingBird.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h sacredBird.h toughBird.h standardBird.h hummingBird.h
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c rifle.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
bullet.o: bullet.h rifle.h flyingObject.h bullet.cpp
	g++ -c bullet.cpp

flyingObject.o: flyingObject.h rifle.h point.h velocity.h uiDraw.h uiInteract.h flyingObject.cpp
	g++ -c flyingObject.cpp

bird.o: bird.h flyingObject.h bird.cpp
	g++ -c bird.cpp

standardBird.o: standardBird.h bird.h standardBird.cpp
	g++ -c standardBird.cpp

sacredBird.o: sacredBird.h bird.h sacredBird.cpp
	g++ -c sacredBird.cpp

toughBird.o: toughBird.h bird.h toughBird.cpp
	g++ -c toughBird.cpp

velocity.o: velocity.h velocity.cpp
	g++ -c velocity.cpp

hummingBird.o: hummingBird.h bird.h hummingBird.cpp
	g++ -c hummingBird.cpp
###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
