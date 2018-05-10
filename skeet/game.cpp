/*************************************************************
 * File: game.cpp
 * Author: Br. Burton
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "game.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"

#include <vector>
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5



/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br)
 : topLeft(tl), bottomRight(br), rifle(br)
{
   //cerr << "game" << endl;
   // Set up the initial conditions of the game
   score = 0;
   levelSpeed = 0;
   // TODO: Set your bird pointer to a good initial value (e.g., NULL)
   bird = NULL;
   // cerr << "gameEnd" << endl;
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
   // cerr << "destruct" << endl;
   // TODO: Check to see if there is currently a bird allocated
   //       and if so, delete it.
	if (bird != NULL)
	{
           delete bird;
           bird = NULL;
        }
        // cerr << "endDestruct" << endl;
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
	if (score < 30)
		levelSpeed = 0;
	else if (score >= 30 && score < 50)
		levelSpeed = 2;
	else if (score >= 50 && score < 70)
		levelSpeed = 4;
	else if (score >= 70 && score < 100)
		levelSpeed = 6;
	else if (score >= 100 && score < 150)
		levelSpeed = 8;
	else if (score >= 150)
		levelSpeed = 10;

   advanceBullets();
   advanceBird();

   handleCollisions();
   cleanUpZombies();
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game :: advanceBullets()
{
   // Move each of the bullets forward if it is alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, so tell it to move forward
         bullets[i].advance();
         
         if (!isOnScreen(bullets[i].getPoint()))
         {
            // the bullet has left the screen
            bullets[i].kill();
         }
         
      }
   }
}

/**************************************************************************
 * GAME :: ADVANCE BIRD
 *
 * 1. If there is no bird, create one with some probability
 * 2. If there is a bird, and it's alive, advance it
 * 3. Check if the bird has gone of the screen, and if so, "kill" it
 **************************************************************************/
void Game :: advanceBird()
{
   //cerr << "advanceBird" << endl;
   if (bird == NULL)
   {
      // there is no bird right now, possibly create one
      // cerr << "resurrection" << endl;
      // "resurrect" it with some random chance
      if (random(0, 30) == 0)
      {
         // create a new bird
         bird = createBird();
      }
      //  cerr << "createBird section" << endl;
   }
  
   else
   {
      // cerr << "else" << endl;
      // we have a bird, make sure it's alive
      if (bird->isAlive())
      {
         // move it forward
         //  cerr << "isALive" << endl;
         bird->advance();
         //  cerr << "terminate advance" << endl;
         // check if the bird has gone off the screen
         if (!isOnScreen(bird->getPoint()))
         {
            // We have missed the bird
            bird->kill();
         }
      }
      //  cerr << "endElse" << endl;
   }
   // cerr << "advanceBirdEnd" << endl;
}

/**************************************************************************
 * GAME :: CREATE BIRD
 * Create a bird of a random type according to the rules of the game.
 **************************************************************************/
Bird* Game :: createBird()
{
   //cerr << "birdCreate" << endl;
   Bird* newBird = NULL;

   // TODO: Fill this in
   int myNumber = random(1, 1000);

   if (myNumber >= 1 && myNumber <= 250)
	   newBird = new StandardBird(levelSpeed);
   else if (myNumber >= 251 && myNumber <= 500)
	   newBird = new SacredBird(levelSpeed);
   else if (myNumber >= 501 && myNumber <= 750)
	   newBird = new ToughBird(levelSpeed);
   else if (myNumber >= 751 && myNumber <= 1000)
	   newBird = new HummingBird(levelSpeed);

   return newBird;
   //cerr << "birdCreateEnd" << endl;
}

/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game :: isOnScreen(const Point & point)
{
   return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
      && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
      && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
      && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a bird and a bullet.
 **************************************************************************/
void Game :: handleCollisions()
{
   // now check for a hit (if it is close enough to any live bullets)
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, see if its too close

         // check if the bird is at this point (in case it was hit)
         if (bird != NULL && bird->isAlive())
         {
            // BTW, this logic could be more sophisiticated, but this will
            // get the job done for now...
            if (fabs(bullets[i].getPoint().getX() - bird->getPoint().getX()) < CLOSE_ENOUGH
                && fabs(bullets[i].getPoint().getY() - bird->getPoint().getY()) < CLOSE_ENOUGH)
            {
               //we have a hit!
               
               // hit the bird
               int points = bird->hit();
               score += points;
               
               // the bullet is dead as well
               bullets[i].kill();
            }
         }
      } // if bullet is alive
      
   } // for bullets
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate bird)
 **************************************************************************/
void Game :: cleanUpZombies()
{
   // cerr << "zombiesStart" << endl;
   // check for dead bird
   if (bird != NULL && !bird->isAlive())
   {
      // the bird is dead, but the memory is not freed up yet
      
      // TODO: Clean up the memory used by the bird
	   delete bird;
	   bird = NULL;
   }
   
   // Look for dead bullets
   vector<Bullet>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      Bullet bullet = *bulletIt;
      // Asteroids Hint:
      // If we had a list of pointers, we would need this line instead:
      //Bullet* pBullet = *bulletIt;
      
      if (!bullet.isAlive())
      {
         // If we had a list of pointers, we would need to delete the memory here...
         
         
         // remove from list and advance
         bulletIt = bullets.erase(bulletIt);
      }
      else
      {
         bulletIt++; // advance
      }
   }
   // cerr << "zombiesEnd" << endl;
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   // cerr << "handleInput" << endl;
   
   // Change the direction of the rifle
   if (ui.isLeft())
   {
      rifle.moveLeft();
   }
   
   if (ui.isRight())
   {
      rifle.moveRight();
   }
   
   // Check for "Spacebar
   if (ui.isSpace())
   {
      Bullet newBullet;
      newBullet.fire(rifle.getPoint(), rifle.getAngle());
      
      bullets.push_back(newBullet);
   }
   // cerr << "endHandleInput" << endl;
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   // cerr << "START DRAW\n";
	// draw the bird

	// TODO: Check if you have a valid bird and if it's alive
	// then call it's draw method
	if(bird != NULL && bird->isAlive())
		bird->draw();
  

   // draw the rifle
   rifle.draw();
   
   // draw the bullets, if they are alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         bullets[i].draw();
      }
   }
   
   // Put the score on the screen
   Point scoreLocation;
   scoreLocation.setX(topLeft.getX() + 5);
   scoreLocation.setY(topLeft.getY() - 5);
   
   drawNumber(scoreLocation, score);
   // cerr << "END DRAW\n";

}

