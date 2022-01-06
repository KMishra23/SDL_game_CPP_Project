CC=g++ 
all_sources=Bullet.cpp Collision.cpp Game.cpp GameObject.cpp Health.cpp KeyboardInputManager.cpp main.cpp Map.cpp player.cpp PlayerAnimationHandler.cpp Scoreboard.cpp TextureManager.cpp Turret.cpp	#all the .cpp files which are to be compiled
all_objs=$(all_sources:.cpp=.o)					 #object files created from the .cpp files

brickbreaker: $(all_objs) 					 #creating excutable file
		$(CC) $(all_sources) -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_image -g -o korok 
%.o: %.c 							 #creating object files
	$(CC) -c $(all_sources) 

clean:								 #removing the executable file and the object file
	rm korok *.o