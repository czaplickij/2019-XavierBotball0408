#include <kipr/botball.h>
int r_motor =0;
int l_motor = 0;
int speed_avg = 45;
int lineSense = 0; //port for linefinder
int sensor = 2000; //sweet spot number for linefinder

int main()
{
    return 0;
}

int forward(int timer){
printf("Moving Forwards \n");
motor(r_motor,speed_avg);
motor(l_motor,speed_avg);
msleep(timer);
}
int reverse(int timer){
printf("Moving Backwards \n");
motor(r_motor,-speed_avg);
motor(l_motor,-speed_avg);
msleep(timer);    
}
int turnRight(int timer){
printf("Turning right \n"); 
motor(l_motor,speed_avg);
motor(r_motor,0);
msleep(timer);
}
int turnLeft(int timer){
printf("Turning left \n"); 
motor(r_motor,speed_avg);
motor(l_motor,0);
msleep(timer);
}
int rightTurn(){
printf("Turning right \n"); 
motor(l_motor,speed_avg);
motor(r_motor,0);
}
int leftTurn(){
printf("Turning left \n"); 
motor(r_motor,speed_avg);
motor(l_motor,0);
}
int findLine(){
while(analog(lineSense)<sensor){
    printf("Finding line");
rightTurn();
}
    while(1){ //change this value, logical test for continuing with findLine 
    if(analog(lineSense)<sensor){
        printf("Not on line, turning left");
        rightTurn(); 
    }
     if(analog(lineSense)>sensor){
     printf("On line, turning right");
          leftTurn();
     }
    }
}