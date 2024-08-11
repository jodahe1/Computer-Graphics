 /* number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include<ctype.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#define M_PI 3.14159265358979323846264338327950288419716939937510
#define false 0
#define true 1
const int BOARD_X = 31;//Declares a constant integer variable BOARD_X with a value of 31.
const int BOARD_Y = 28;//Declares a constant integer variable BOARD_Y with a value of 28.
int board_array[BOARD_X][BOARD_Y] = // Initializes a 2D array called board_array with dimensions BOARD_X by BOARD_Y and initializes it with specific values for a game board layout.
 {{8,5,5,5,5,5,5,5,5,5,5,5,5,1,1,5,5,5,5,5,5,5,5,5,5,5,5,7},
{6,0,0,0,0,0,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,0,0,0,0,0,0,6},
{6,0,8,1,1,7,0,8,1,1,1,7,0,2,4,0,8,1,1,1,7,0,8,1,1,7,0,6},
{6,0,2,11,11,4,0,2,11,11,11,4,0,2,4,0,2,11,11,11,4,0,2,11,11,4,0,6},
{6,0,9,3,3,10, 0,9,3,3,3,10,0,9,10,0,9,3,3,3,10,0,9,3,3,10,0,6},
{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
{6,0,8,1,1,7,0,8,7,0,8,1,1,1,1,1,1,7,0,8,7,0,8,1,1,7,0,6},
{6,0,9,3,3,10,0,2,4,0,9,3,3,11,11,3,3,10,0,2,4,0,9,3,3,10,0,6},
{6,0,0,0,0,0,0,2,4,0,0,0,0,2,4,0,0,0,0,2,4,0,0,0,0,0,0,6},
{9,5,5,5,5,7,0,2,11,1,1,7,0,2,4,0,8,1,1,11,4,0,8,5,5,5,5,10},
{0,0,0,0,0,6,0,2,11,3,3,10,0,9,10,0,9,3,3,11,4,0,6,0,0,0,0,0},
{0,0,0,0,0,6,0,2,4,0,0,0,0,0,0,0,0,0,0,2,4,0,6,0,0,0,0,0},
{0,0,0,0,0,6,0,2,4,0,8,5,5,1,1,5,5,7,0,2,4,0,6,0,0,0,0,0},
{5,5,5,5,5,10,0,9,10,0,6,0,0,0,0,0,0,6,0,9,10,0,9,5,5,5,5,5},
{0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0},
{5,5,5,5,5,7,0,8,7,0,6,0,0,0,0,0,0,6,0,8,7,0,8,5,5,5,5,5},
{0,0,0,0,0,6,0,2,4,0,9,5,5,5,5,5,5,10,0,2,4,0,6,0,0,0,0,0},
{0,0,0,0,0,6,0,2,4,0,0,0,0,0,0,0,0,0,0,2,4,0,6,0,0,0,0,0},
{0,0,0,0,0,6,0,2,4,0,8,1,1,1,1,1,1,7,0,2,4,0,6,0,0,0,0,0},
{8,5,5,5,5,10,0,9,10,0,9,3,3,11,11,3,3,10,0,9,10,0,9,5,5,5,5,7},
{6,0,0,0,0,0,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,0,0,0,0,0,0,6},
{6,0,8,1,1,7,0,8,1,1,1,7,0,2,4,0,8,1,1,1,7,0,8,1,1,7,0,6},
{6,0,9,3,11,4,0,9,3,3,3,10,0,9,10,0,9,3,3,3,10,0,2,11,3,10,0,6},
{6,0,0,0,2,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,4,0,0,0,6},
{2,1,7,0,2,4,0,8,7,0,8,1,1,1,1,1,1,7,0,8,7,0,2,4,0,8,1,4},
 {2,3,10,0,9,10,0,2,4,0,9,3,3,11,11,3,3,10,0,2,4,0,9,10,0,9,3,4},
{6,0,0,0,0,0,0,2,4,0,0,0,0,2,4,0,0,0,0,2,4,0,0,0,0,0,0,6},
{6,0,8,1,1,1,1,11,11,1,1,7,0,2,4,0,8,1,1,11,11,1,1,1,1,7,0,6},
{6,0,9,3,3,3,3,3,3,3,3,10,0,9,10,0,9,3,3,3,3,3,3,3,3,10,0,6},
{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
{9,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,10}};
int pebble_array[BOARD_X][BOARD_Y] =// Initializes a 2D array called pebble_array with dimensions BOARD_X by BOARD_Y and initializes it with specific values for pebbles on the game board.
 {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0},
 {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
 {0,3,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,3,0},
 {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
 {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
 {0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0},
 {0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0},
 {0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0},
 {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
 {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
 {0,3,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,3,0},
 {0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0},
 {0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0},
 {0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0},
 {0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0},
 {0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0},
 {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
GLubyte list[5];//Declares an array of type GLubyte with a size of 5.
int tp_array[31][28];
int pebbles_left;//Declares an integer variable to store the number of pebbles left in the game.
double speed1 = 0.1;
double angle1 = 90;
double a=13.5, b=23;
bool animate = false;
int lives=3;// Declares an integer variable to store the number of lives the player has.
int points=0;//Declares an integer variable to store the player's points.
void keys();
unsigned char ckey='w';
void mykey(unsigned char key,int x,int y);
bool Open(int a,int b);
void Move()//Defines a function named Move that handles player movement based on key inputs.
{
a += speed1*cos(M_PI/180*angle1);
b += speed1*sin(M_PI/180*angle1);//The function checks for key inputs and updates the animate flag and angle of movement based on the key pressed (UP, DOWN, LEFT, RIGHT) and whether the next position is open.
if(animate&&ckey==GLUT_KEY_UP&& (int) a - a > -0.1 && angle1 != 270) //w
{
if (Open(a,b-1))
{
animate = true;
 angle1 = 270;
 }
 }
else if(animate&&ckey==GLUT_KEY_DOWN&& (int) a - a > -0.1 && angle1 != 90)// s
{
if (Open(a,b+1))
{
animate = true;
angle1= 90;
}
}
else if(animate&&ckey==GLUT_KEY_LEFT&& (int) b - b > -0.1 && angle1 != 180)//a
{
if (Open(a-1,b))
{
animate = true;
angle1 = 180;
}
}
else if(animate&&ckey==GLUT_KEY_RIGHT&& (int) b - b > -0.1 && angle1 != 0)//d
{
if (Open(a+1,b))
{
animate = true;
angle1 = 0;
}
}
}
void Pac(void)//Defines a function named Pac responsible for drawing the Pacman character.
{
//Draw Pacman
glColor3f(0,1,1);
glPushMatrix();
 glTranslatef(a,-b,0);
glTranslatef(0.5,0.6,0);
 glTranslatef((float)BOARD_X/-2.0f,(float)BOARD_Y/2.0f,0.5);
glutSolidSphere(0.5,15,10);
glPopMatrix();
}
//Monster Drawing And Moving Begins
bool open_move[4];// Declares an array of boolean values to store open movement directions for monsters.
bool gameover = false;
int num_ghosts = 4;//Declares an integer variable to store the number of ghosts in the game.
int start_timer=3;//Initializes a timer for starting the game.
class Ghost
{
 private:
 public:
 bool edible;
 int edible_max_time;
 int edible_timer;

 bool eaten;
 bool transporting;
 float color[3];
 double speed;
 double max_speed;
 bool in_jail;
 int jail_timer;
 double angle;
 double x, y;
 Ghost(double, double);

 ~Ghost(void);
 void Move(); //Move the Monster
 void Update(void); //Update Monster State
 void Chase(double, double, bool*); //Chase Pacman
 bool Catch(double, double); //collision detection
 void Reinit(void);//resets the ghost's properties to their initial state.
 void Vulnerable(void);
 void Draw(void); //Draw the Monster
 void game_over(void);
};
Ghost *ghost[4];//ghost is declared as an array of 4 Ghost pointers to store the ghost objects.
Ghost::~Ghost(void){}
Ghost::Ghost(double tx, double ty)//The Ghost constructor defines how to initialize a new Ghost object
{
tx = x;
ty = y;//tx, ty parameters set the initial position
angle = 90;
speed = max_speed=1;
color[0] = 1;
color[1] = 0;
color[2] = 0;//color is set to red
eaten = false;
edible_max_time =300;//State values like eaten, edible timers are reset
edible = false;
in_jail = true;
jail_timer = 30;
}
void Ghost::Reinit(void)
{
edible = false;
in_jail = true;
angle = 90;
}
//Move Monster
void Ghost::Move()
{
x += speed*cos(M_PI/180*angle);
y += speed*sin(M_PI/180*angle);
}
void Ghost::game_over()
{
}
void Ghost::Update(void)
{
if ((int)x == 0 && (int) y == 14 && (!(transporting)))//Checks if the ghost is at the left edge of the board and not currently transporting, then sets the angle to 180.
{
angle=180;
}
if (x < 0.1 && (int) y == 14)//Checks if the ghost is close to the left edge, moves it to the right edge and sets the transporting flag to true.
{
x = 26.9;
transporting = true;
}
if ((int)x == 27 && (int) y == 14 && (!(transporting)))//Checks if the ghost is at the right edge of the board and not currently transporting, then sets the angle to 0.
{
angle=0;
}
if (x > 26.9 && (int) y == 14)//Checks if the ghost is close to the right edge, moves it to the left edge, and sets the transporting flag to true.
{
x = 0.1;
transporting = true;
}
if ((int)x == 2 || (int)x == 25)//Resets the transporting flag if the ghost is not at the edges.
transporting = false;
if (((int) x < 5 || (int) x > 21) && (int) y == 14 && !edible && !eaten)//If the ghost is not edible, not eaten, and at a specific y position, reduces its speed.
speed = max_speed/2;
speed = max_speed;
//edibility
if (edible_timer == 0 && edible && !eaten)
{
edible = false;
speed = max_speed;
}
 if (edible)
edible_timer--;
//JAIL
if (in_jail && (int) (y+0.9) == 11)//Handles the behavior of the ghost when it is in jail, moving it out of jail when reaching a specific y position and changing its angle.
{
in_jail = false;
angle = 180;
}
if (in_jail && ((int)x == 13 || (int)x == 14))
{
angle = 270;
}
//if time in jail is up, position for exit
if (jail_timer == 0 && in_jail)
{
//move right to exit
if (x < 13)
angle = 0;
if (x > 14)
angle = 180;
}
//decrement time in jail counter
if (jail_timer > 0)
jail_timer--;
//EATEN GHOST SEND TO JAIL
if (eaten && ((int) x == 13 || (int) (x+0.9) == 14) && ((int)y > 10 && (int) y < 15))//And its x position is at the jail entrance (int x == 13 or x+0.9 == 14)
{//And its y position is in the range of the jail entrance (int y > 10 && int y < 15)
    //it is checking if the ghost is eaten (eaten == true)
in_jail = true;
angle = 90;//Set its angle to point into the jail (angle = 90).
if((int) y == 14)
{
eaten = false;//reset eaten to false, set speed back to max, initialize jail timer.
speed = max_speed;
jail_timer = 66;
x = 11;
}
}
}
bool Ghost::Catch(double px, double py)// Defines a member function Catch for the Ghost class, responsible for collision detection with Pacman.
{
// Collision Detection
if (px - x < 0.2 && px - x > -0.2 && py - y < 0.2 && py - y > -0.2)//Checks if the distance between the ghost and Pacman is within a small range, and if so, returns true indicating a collision.other wise false
{
return true;
}
return false;
}
//called when pacman eats a super pebble
void Ghost::Vulnerable(void)
{
if (!(edible))
{
angle = ((int)angle + 180)%360;
speed = max_speed;
}
edible = true;
edible_timer = edible_max_time;
//speed1=0.15;
}
void Ghost::Chase(double px, double py, bool *open_move)//handling the ghost's behavior when chasing Pacman.
{
 int c;
if (edible)
c = -1;
else
c = 1;
bool moved = false;//Determines the direction in which the ghost should move based on Pacman's position and open movement directions.
if ((int) angle == 0 || (int) angle == 180)
{
if ((int)c*py > (int)c*y && open_move[1])
angle = 90;
else if ((int)c*py < (int)c*y && open_move[3])
angle = 270;
}
else if ((int) angle == 90 || (int) angle == 270)
{
if ((int)c*px > (int)c*x && open_move[0])
angle = 0;
else if ((int)c*px < (int)c*x && open_move[2])
angle = 180;
}
//Random Moves Of Monsters
if ((int) angle == 0 && !open_move[0])
angle = 90;
if ((int) angle == 90 && !open_move[1])
angle = 180;
if ((int) angle == 180 && !open_move[2])
angle = 270;
 if ((int) angle == 270 && !open_move[3])
angle = 0;
if ((int) angle == 0 && !open_move[0])
angle = 90;
}
void Ghost::Draw(void)//Defines a member function Draw for the Ghost class, responsible for drawing the ghost.
{
if (!edible)//It checks if the ghost is edible (!edible)
glColor3f(color[0],color[1],color[2]);
else
{
if (edible_timer < 150)
glColor3f((edible_timer/10)%2,(edible_timer/10)%2,1);//Set color based on timer mod 2 to flash between two colors
if (edible_timer >= 150)
glColor3f(0,0,1);//Set color to blue
}
if (eaten)
glColor3f(1,1,0); //When Eaten By PacMan Change Color To Yellow
glPushMatrix();
glTranslatef(x,-y,0);
glTranslatef(0.5,0.6,0);
glTranslatef((float)BOARD_X/-2.0f, (float)BOARD_Y/2.0f,0.5);
glutSolidSphere(.5,10,10);
glPopMatrix();
}//Uses OpenGL commands to draw a solid sphere representing the ghost at its position on the board.
void tp_restore(void)//Defines a function tp_restore to restore the pebble array to its original state.
{
for (int ISO = 0; ISO < BOARD_X; ISO++)
{
for (int j = 0; j < BOARD_Y; j++)
{
tp_array[ISO][j] = pebble_array[ISO][j];
}
}
pebbles_left = 244;//Copies the pebble array values back to the teleport array and resets the number of pebbles left.
}
void Draw(void)// Defines a function Draw to draw the game board elements.
{
glColor3f(1,0,1);
//split board drawing in half to avoid issues with depth
for (int ISO = 0; ISO < BOARD_X; ISO++)//Two nested loops iterate through the board_x and board_y/2 dimensions to draw the top half of the board.
{
for (int j = 0; j < BOARD_Y/2; j++)
{
glColor3f(0,0,1);
int call_this = 0;
glPushMatrix();//Push/pop matrix and translate to board position.
glTranslatef(-(float) BOARD_X / 2.0f,-(float) BOARD_Y / 2.0f, 0);
 glTranslatef(j, BOARD_Y - ISO,0);
glPushMatrix();
glTranslatef(0.5,0.5,0);
switch (board_array[ISO][j])//Switch/case on tile type from board array:
{//Applies rotations depending on tile type
case 4:
glRotatef(90.0,0,0,1);
case 3:
glRotatef(90.0,0,0,1);
case 2:
glRotatef(90.0,0,0,1);
case 1:
call_this = 1;
break;
case 6:
glRotatef(90.0,0,0,1);
case 5:
call_this = 2;
break;
case 10:
glRotatef(90.0,0,0,1);
case 9:
glRotatef(90.0,0,0,1);
case 8:
glRotatef(90.0,0,0,1);
case 7:
call_this = 3;
break;
}
glScalef(1,1,0.5);
glTranslatef(-0.5,-0.5,0);
glCallList(list[call_this]);
glPopMatrix();
//now put on the top of the cell
if (call_this != 0 || board_array[ISO][j] == 11)
{
glTranslatef(0,0,-0.5);
glCallList(list[4]);
}
glPopMatrix();
if (tp_array[ISO][j] > 0)//Draws pebbles on the board if their value is greater than 0, indicating that they are still present.
{
 glColor3f(0,300,1/(float)tp_array[ISO][j]);
glPushMatrix();
glTranslatef(-(float) BOARD_X / 2.0f,-(float) BOARD_Y / 2.0f, 0);
glTranslatef(j, BOARD_Y - ISO,0);
glTranslatef(0.5,0.5,0.5);
glutSolidSphere(0.1f*((float)tp_array[ISO][j]),6,6);
glPopMatrix();
}
}
}
 int ISO;//The following nested loops iterate over the game board elements to draw them using OpenGL commands.
for (ISO= 0; ISO< BOARD_X; ISO++)
{
for (int j = BOARD_Y-1; j >= BOARD_Y/2; j--)//The code within the loops sets the color, position, and rotation of elements based on the values in the board_array.
{
 glColor3f(0,0,1);//Default blue color is set.
int call_this = 0;
glPushMatrix();
glTranslatef(-(float) BOARD_X / 2.0f,-(float) BOARD_Y / 2.0f, 0);//The outer for loop iterates through each row from bottom to halfway up the board
glTranslatef(j, BOARD_Y - ISO,0);
glPushMatrix();
glTranslatef(0.5,0.5,0);
switch (board_array[ISO][j])//Apply necessary rotations
{
case 4:
glRotatef(90.0,0,0,1);
case 3:
glRotatef(90.0,0,0,1);
case 2:
glRotatef(90.0,0,0,1);
case 1:
call_this = 1;
break;
case 6:
glRotatef(90.0,0,0,1);
case 5:
call_this = 2;
break;
case 10:
glRotatef(90.0,0,0,1);
case 9:
glRotatef(90.0,0,0,1);
case 8:
glRotatef(90.0,0,0,1);
case 7:
call_this = 3;
break;
}
glScalef(1,1,0.5);
glTranslatef(-0.5,-0.5,0);
glCallList(list[call_this]);//Set call_this value to index display list  and Calls display list drawing optimized tile graphic.
 glPopMatrix();
//now put on top
if (call_this != 0 || board_array[ISO][j] == 11)
{
glTranslatef(0,0,-0.5);
glCallList(list[4]);
}
glPopMatrix();
if (tp_array[ISO][j] > 0)//If the element represents a teleport point, a sphere is drawn at that position with a size based on the value in the tp_array.
{
glColor3f(0,300,1/(float)tp_array[ISO][j]);
glPushMatrix();
 glTranslatef(-(float) BOARD_X / 2.0f,-(float) BOARD_Y / 2.0f, 0);
glTranslatef(j, BOARD_Y - ISO,0);
glTranslatef(0.5,0.5,0.5);
glutSolidSphere(0.1f*((float)tp_array[ISO][j]),6,6);
glPopMatrix();
}
}
}
 Pac();//After drawing the board elements, the Pac() function is called to draw the Pacman character.
}
bool Open(int a, int b)//The function checks the value at the given position in board_array and returns true if it's open (value greater than 0), otherwise false.
{
if (board_array[b][a] > 0)
{
return false;
}
return true;
}
void RenderScene();
void mykey(unsigned char key,int x,int y)// Defines a function mykey to handle regular key press events.
{
if (start_timer > 0)//If the start_timer is greater than 0, it decrements the timer.
{
start_timer--;
}
}
void specialDown(int key,int x,int y)
{
if (start_timer > 0)
start_timer--;
ckey=key;//Sets the ckey based on the key pressed and handles movement based on the key pressed, angle, and open positions on the board.
if(key==GLUT_KEY_UP&& (int) a - a > -0.1 && angle1 != 270) //w
{
if (Open(a, b - 1))
{
animate = true;
angle1 = 270;
 }
 }
 //The function sets the animate flag to true and updates the angle based on the key pressed if the movement is possible.
else if(key==GLUT_KEY_DOWN&& (int) a - a > -0.1 && angle1 != 90)// s
{
if (Open(a,b + 1))
{
animate = true;
angle1= 90;
}
}
 else if(key==GLUT_KEY_LEFT&& (int) b - b > -0.1 && angle1 != 180)//a
{
if (Open(a-1,b))
{
animate = true;
angle1 = 180;
}
}
else if(key==GLUT_KEY_RIGHT&& (int) b - b > -0.1 && angle1 != 0)//d
{
if (Open(a+1, b))
{
animate = true;
angle1 = 0;
}
}
}
void specialUp(int key,int x,int y)//Defines a function specialUp to handle special key up events, but the function body is empty.
{
}
void P_Reinit()//resets Pacman's position, state variables to restart gameplay.
{
a = 13.5;//Sets the initial position (a, b), angle (angle1), and animation state for Pacman and calls the Pac() function to draw Pacman.
b = 23;
angle1 = 90;
animate = false;
Pac();
}
void G_Reinit(void)//handles resetting the ghosts - positions, timers, speeds, colors.
{
start_timer = 3;
//ghost initial starting positions
int start_x[4] = {11,12,15,16};//Initializes the start timer and sets initial positions, properties, and colors for each ghost based on the start_x and ghost_colors arrays.
float ghost_colors[4][3] = {{255,0,0},{120,240,120},{255,200,200},{255,125,0}};
for (int i = 0; i < num_ghosts; i++)//Loops through each ghost, resets their properties, and assigns colors based on the ghost index.
{
ghost[i]->Reinit();
ghost[i]->x = start_x[i];
ghost[i]->y = 14;
ghost[i]->eaten = false;
ghost[i]->jail_timer = i*33 + 66;
ghost[i]->max_speed = 0.1 - 0.01*(float)i;
ghost[i]->speed = ghost[i]->max_speed;
//colorize ghosts
for (int j = 0; j < 3; j++)
ghost[i]->color[j] = ghost_colors[i][j]/255.0f;
}
}
void renderBitmapString(float x, float y, void *font, char *string)// Defines a function to render a string using a specified font at the given position.
{
 char *c;
 glRasterPos2f(x,y);
 for (c=string; *c != '\0'; c++)
 {
 glutBitmapCharacter(font, *c);
 }
}
void Write(char *string)// Defines a function to write a string using the Helvetica 18 font.
{
 while(*string)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
}
void print(char *string)//Defines a function to print a string using the Times Roman 24 font.
{
 while(*string)
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}
//Display Function->This Function Is Registered in glutDisplayFunc
void RenderScene()//Defines the main display function for rendering the game scene using OpenGL commands.
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//Through Movement->From One End To The Other
if ((int)a == 27 && (int) b == 14 && angle1 == 0)//Handles Pacman's movement across the board, collision detection, and interactions with pebbles and super pebbles.
{
a = 0;
animate = true;
}
else
if ((int)(a + 0.9) == 0 && (int) b == 14 && angle1 == 180)
{
a = 27;
animate = true;
}
//Collision Detection For PacMan
if (animate)
Move();
if(!(Open((int)(a + cos(M_PI/180*angle1)),
(int)(b + sin(M_PI/180*angle1)))) &&
a - (int)a < 0.1 && b - (int)b < 0.1)
 animate = false;
if (tp_array[(int)(b+0.5)][(int)(a+0.5)]== 1)
{
tp_array[(int)(b+0.5)][(int)(a+0.5)]= 0;
pebbles_left--;
points+=1;
}
//Super Pebble Eating
else if(tp_array[(int)(b+0.5)][(int)(a+0.5)] == 3)
{
tp_array[(int)(b+0.5)][(int)(a+0.5)]= 0;
pebbles_left--;
points+=5;
for (int i = 0; i < 4; i++)
{
if (!ghost[i]->eaten)
ghost[i]->Vulnerable(); //Calls A Function To Make Monster Weak
}
}
//All The Pebbles Have Been Eaten
if (pebbles_left == 0)
{
G_Reinit();
P_Reinit();
tp_restore();
points=0;
lives=3;
}
if (!gameover)
Draw();
for (int d = 0; d < num_ghosts; d++)
{
if (!gameover && start_timer == 0)
ghost[d]->Update();
if (!ghost[d]->in_jail &&
ghost[d]->x - (int)ghost[d]->x < 0.1 && ghost[d]->y - (int)ghost[d]->y < 0.1)
{
bool open_move[4];
//Finding Moves
for (int ang = 0; ang < 4; ang++)
{
open_move[ang] = Open((int)(ghost[d]->x + cos(M_PI/180*ang*90)),
(int)(ghost[d]->y + sin(M_PI/180*ang*90)));
}
 //Chase Pac Man
if (!ghost[d]->eaten)
{
if(ghost[d]->x - (int)ghost[d]->x < 0.1 && ghost[d]->y - (int)ghost[d]->y < 0.1)
ghost[d]->Chase(a, b, open_move);
}
else
{
if(ghost[d]->x - (int)ghost[d]->x < 0.1 && ghost[d]->y - (int)ghost[d]->y < 0.1)
ghost[d]->Chase(13, 11, open_move);
}
}
if (ghost[d]->in_jail && !(Open((int)(ghost[d]->x + cos(M_PI/180*ghost[d]->angle)),
(int)(ghost[d]->y + sin(M_PI/180*ghost[d]->angle)))) && ghost[d]->jail_timer > 0
&&ghost[d]->x - (int)ghost[d]->x < 0.1 && ghost[d]->y - (int)ghost[d]->y < 0.1)
 {
 ghost[d]->angle = (double)(((int)ghost[d]->angle + 180)%360);
 }
if (!gameover && start_timer == 0)
ghost[d]->Move();
 ghost[d]->Draw();
if(!(ghost[d]->eaten))
{
bool collide = ghost[d]->Catch(a,b);
//Monster Eats PacMan
if (collide && !(ghost[d]->edible))//Handles interactions between ghosts and Pacman, decrementing lives if caught, and triggering the game over state if lives reach zero.
{
lives--;
if (lives == 0)
{
gameover = true;
lives=0;
ghost[d]->game_over();
 }
P_Reinit();
d = 4;
}
//PacMan Eats Monster And Sends It To Jail
else if (collide && ((ghost[d]->edible)))//Checks if Pacman collides with an edible ghost.
{
ghost[d]->edible = false;//If the condition is met, the ghost's edible status is set to false, indicating it has been eaten.
 ghost[d]->eaten = true;//The ghost's eaten status is set to true, and its speed is increased.
ghost[d]->speed = 1;
}
}
}
if(gameover==true)//If the game is over, the screen is cleared, and a "GAME OVER" message is displayed in red.
{
glColor3f(1,0,0);
renderBitmapString(-5, 0.5,GLUT_BITMAP_HELVETICA_18 ,"GAME OVER");
}
 char tmp_str[40];//Various text messages displaying points, Pacman label, and remaining lives are rendered on the screen.
 glColor3f(1, 1, 0);
 glRasterPos2f(10, 18);
sprintf(tmp_str, "Points: %d", points);
 Write(tmp_str);
glColor3f(1, 0, 0);
 glRasterPos2f(-5, 18);
sprintf(tmp_str, "PAC MAN");
 print(tmp_str);
glColor3f(1, 1, 0);
 glRasterPos2f(-12, 18);
sprintf(tmp_str, "Lives: %d", lives);
 Write(tmp_str);
 glutPostRedisplay();
 glutSwapBuffers();
}
void create_list_lib()// Defines a function to create display lists for different walls in the game maze.
{//create_list_lib() defines OpenGL display lists to render maze walls/tiles efficiently.
//Set Up Maze Using Lists
list[1] = glGenLists(1);
 glNewList(list[1], GL_COMPILE);
//North Wall
glBegin(GL_QUADS);
glColor3f(0,0,1);
glNormal3f(0.0, 1.0, 0.0);
glVertex3f(1.0, 1.0, 1.0);
glVertex3f(1.0, 1.0, 0.0);
glVertex3f(0.0, 1.0, 0.0);
glVertex3f(0.0, 1.0, 1.0);
glEnd();
glEndList();
 list[2] = glGenLists(1);
 glNewList(list[2], GL_COMPILE);

 glBegin(GL_QUADS);
//North Wall
glColor3f(0,0,1);
glNormal3f(0.0, 1.0, 0.0);
glVertex3f(1.0, 1.0, 1.0);
glVertex3f(1.0, 1.0, 0.0);
glVertex3f(0.0, 1.0, 0.0);
glVertex3f(0.0, 1.0, 1.0);
 //South Wall
 glColor3f(0,0,1);
 glNormal3f(0.0, -1.0, 0.0);
glVertex3f(1.0, 0.0, 0.0);
glVertex3f(1.0, 0.0, 1.0);
glVertex3f(0.0, 0.0, 1.0);
glVertex3f(0.0, 0.0, 0.0);
glEnd();
glEndList();
 list[3] = glGenLists(1);
 glNewList(list[3], GL_COMPILE);
glBegin(GL_QUADS);
 //North Wall
glColor3f(0,0,1);
glNormal3f(0.0f, 1.0f, 0.0f);
glVertex3f(1.0, 1.0, 1.0);
glVertex3f(1.0, 1.0, 0.0);
glVertex3f(0.0, 1.0, 0.0);
glVertex3f(0.0, 1.0, 1.0);
 //East Wall
glColor3f(0,0,1);
glNormal3f(1.0, 0.0, 0.0);
glVertex3f(1.0, 1.0, 0.0);
glVertex3f(1.0, 1.0, 1.0);
glVertex3f(1.0, 0.0, 1.0);
glVertex3f(1.0, 0.0, 0.0);
glEnd();
glEndList();
 list[4] = glGenLists(1);
 glNewList(list[4], GL_COMPILE);
glBegin(GL_QUADS);
//Top Wall
glColor3f(-1,0.3,0);
glNormal3f(1.0, 0.0, 1.0);
 glVertex3f(1, 1, 1.0);
 glVertex3f(0, 1, 1.0);
 glVertex3f(0, 0, 1.0);
 glVertex3f(1, 0, 1.0);
glEnd();
glEndList();
}
void init()//Defines a function to draw a polygon for erasing purposes, but the function body is empty.
{
 /* float color[4];
Enable Lighting.
glEnable(GL_LIGHT0);
glEnable(GL_LIGHTING);
Ambient And Diffuse Lighting
glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
glEnable(GL_COLOR_MATERIAL);
 color[0] = 1.0f; color[1] = 1.0f; color[2] = 0.0f; color[3] = 0.0f;
glLightfv(GL_LIGHT0, GL_DIFFUSE, color);
color[0] = 1.0f; color[1] = 0.0f; color[2] = 1.0f; color[3] = 1.0f;
glLightfv(GL_LIGHT0, GL_AMBIENT, color);*/
glEnable(GL_NORMALIZE);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(60,1.33,0.005,100);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
 gluLookAt(-1.5, 0, 40, -1.5, 0, 0, 0.0f,1.0f,0.0f);//he function sets up lighting, perspective projection, and the camera position using gluPerspective() and gluLookAt().
}
void erase()//Defines a function to draw a polygon for erasing purposes, but the function body is empty.
{
glColor3f(0.1,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0.5,0);
glVertex2f(0.25,0.5);
glEnd();
}
int main(int argc,char **argv)// The main function where the program execution starts.
{
 glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );//Initializes GLUT, sets up the display mode, window size, and position.
glutInitWindowSize(1200, 780);
glutInitWindowPosition(0,0);
glutCreateWindow("Pac GL 3D");
 init();
 glutDisplayFunc(RenderScene);
create_list_lib();
glutKeyboardFunc(mykey);
glutSpecialFunc(specialDown);
glutSpecialUpFunc(specialUp);
 glEnable(GL_DEPTH_TEST);
int start_x[4] = {11,12,15,16};
for (int ISO = 0; ISO < num_ghosts; ISO++)
{
ghost[ISO] = new Ghost(start_x[ISO],14);//Creates and initializes ghost objects, sets their positions, colors, and properties.
}
float ghost_colors[4][3] = {{255,0,0},{120,240,120},{255,200,200},{255,125,0}};//ghost_colors array defines the default RGB colors for each ghost as floats between 0-1.
int ISO;//ISO variable declared for ghost loop index.
for (ISO = 0; ISO < num_ghosts; ISO++)
{
ghost[ISO]->x = start_x[ISO];
ghost[ISO]->y = 14;
ghost[ISO]->eaten = false;
ghost[ISO]->max_speed = 0.1 - 0.01*(float)ISO;//Sets initial speed to max speed.
ghost[ISO]->speed = ghost[ISO]->max_speed;//Sets initial speed to max speed.
//colorize ghosts
for (int j = 0; j < 3; j++)//Initializes the teleport array based on the pebble array and sets the number of remaining pebbles.
ghost[ISO]->color[j] = ghost_colors[ISO][j]/255.0f;
}
for ( ISO = 0; ISO < BOARD_X; ISO++)
 {
 for (int j = 0; j < BOARD_Y; j++)
 {
 tp_array[ISO][j] = pebble_array[ISO][j];
 }
 }
 pebbles_left = 244;
 glShadeModel(GL_SMOOTH);
glutMainLoop();//The main loop using glutMainLoop() to handle events and update the display.
return 0;
}
