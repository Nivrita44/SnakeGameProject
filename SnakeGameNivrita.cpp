#include<bits/stdc++.h>
#include<graphics.h>
#include<time.h>


int main()
{
    int gd = DETECT,gm,key_dir,foodX,foodY,snakeX[200],snakeY[200];
    initgraph(&gd,&gm,(char*)" ");



    int  delayTime = 200;
    int food = 0;
    int body= 500;
    int p_dir = 1;
    int length = 1;
    bool game = true;

        snakeX[200] = {0};
        snakeY[200] = {0};



    snakeX[0] = 200,snakeY[0] = 200;
    foodX = 200, foodY = 200;
    key_dir = rand()%2;




    while(game)
    {
        setfillstyle(SOLID_FILL,YELLOW);
        bar(0,0,630,470);

        setfillstyle(SOLID_FILL,RED);

        bar(0,0,630,10);

        bar(0,0,10,470);

        bar(0,470,630,460);

        bar(620,10,630,470);

        bar(50,220,40,60);




        setfillstyle(SOLID_FILL,	BLACK);

        if(snakeX[0] == foodX && snakeY[0] == foodY)
        {
            length = length + 2;
            food = food +1 ;
            delayTime = delayTime - 2;

            bar(foodX,foodY,foodX + 10 , foodY + 10 );

            do{
                foodX = (10 + rand() % 600);
                foodY = (10 + rand() % 450);
            }while(getpixel(foodX,foodY) != 0 && foodX > 10 && foodY>10);



            foodX = foodX / 10;
            foodX = foodX * 10;
            foodY = foodY / 10;
            foodY = foodY * 10;



            if(foodX == 10){
                foodX = rand() % 10 + 5;
                foodX = food * 10;
            }
            else if(foodY == 10)
            {
                foodY = rand() % 10 + 5;
                foodY = foodY * 10;
            }

        }

        bar(foodX,foodY,foodX + 10, foodY + 10);

        setfillstyle(SOLID_FILL,	CYAN);



        if(GetAsyncKeyState(VK_RIGHT)||GetAsyncKeyState('D')){
            key_dir = 1;
        }
        else if(GetAsyncKeyState(VK_LEFT)||GetAsyncKeyState('A')){
            key_dir = 2;
        }
        else if(GetAsyncKeyState(VK_UP)||GetAsyncKeyState('W')){
            key_dir = 3;
        }
        else if(GetAsyncKeyState(VK_DOWN)||GetAsyncKeyState('S')){
            key_dir = 4;
        }
        else {
                key_dir = 0;
        }



        switch(key_dir)
        {
        case 0:
            if(p_dir == 1){
                snakeX[0] = snakeX[0] + 10;
            }
            else if(p_dir == 2){
                snakeX[0] = snakeX[0] - 10;
            }
            else if(p_dir == 3){
                snakeY[0] = snakeY[0] - 10;
            }
            else if(p_dir == 4){
                snakeY[0] = snakeY[0] + 10;
            }
            else{
                key_dir = 0;
            }
            break;

        case 1:
            snakeX[0] = snakeX[0] + 10;
            p_dir = 1;
            break;
        case 2:
            snakeX[0] = snakeX[0] - 10;
            p_dir = 2;
            break;
        case 3:
            snakeY[0] = snakeY[0] - 10;
            p_dir = 3;
            break;
        case 4:
            snakeY[0] = snakeY[0] + 10;
            p_dir = 4;
            break;

        }



       for(int i =0; i < length; i++)
       {
           bar(snakeX[i], snakeY[i], snakeX[i] + 10, snakeY[i] + 10);
       }



       for(int i = 199; i > 0; i--)
       {
           snakeX[i] = snakeX[i - 1];
           snakeY[i] = snakeY[i - 1];
       }



    for(int i = 2; i < length; i++)
    {
        if(snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
        {
            body = i;
            break;
        }
    }

    delay(delayTime);



    if(snakeX[0] >= 615 || snakeX[0] <=5 || snakeY[0] <= 5|| snakeY[0] >= 455 || (snakeX[0]==40 && snakeY[0]<=220 && snakeY[0]>=60)){
        std::cout<<"Snake bumped into the wall !!\n\n";
        game = false;
    }



    if(snakeX[0] == snakeX[body] && snakeY[0] ==  snakeY[body] ){
        std::cout<<"Snake bumped into itself !!!\n\n";
        game = false;
    }

    }


    std::cout<<"Your score is : " <<(food-1)*10<<"\n\n";
    std::cout<<"Game Over !!!\n\n";
    getch();
    return 0;
}
