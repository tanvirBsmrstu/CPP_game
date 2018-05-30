#include<iostream>
#include <windows.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
using namespace std;
void initboard();
int key_hit();
void play();
void drow_board_GREEN();
void drow_board_init();
void drow_brick();
void clr_brick();
void score_board();
void score_board_clr();
int check_accident();
void p_clear();
void p_drow();
void hs();
void instruction();
void initial_bricks_ary();
void game_over();
void push_game();
void minimize_x_axis(int a[][3],int size);
void upper_brick(int x1,int rhi,int rx2,int rclor);
void upper_brick_clr(int x1,int rhi,int rx2,int new_endl);
void lower_brick(int x1,int rhi,int rx2,int rclor);
void lower_brick_clr(int x1,int rhi,int rx2,int new_endl);
void dedicated_to();
void cradit();
#define m 20  //wide of bricks
#define ary_size 5                              //lob = lower_brick array  //upb=upper brick array
#define ary_size2 5
#define min_brk_height 50
#define min_div_btn_ulb 40
clock_t tm;
int p_low=-10,p_hi=10,p_forwd=30,p_backwd=0,maxScrLen,maxScrDepth,maxScrTop=20,scrLeft=20,midx,midy,upb_area [ary_size][3],lob_area[ary_size2][3],s=0,score=0,hscore=0;

int main()
{
    int gdrive=DETECT,gmode;
    initgraph(&gdrive,&gmode,"");
start :
    cleardevice();
    initboard();
    char c=getch();
    switch(c)
    {
    case '1' :
        cleardevice();
        score=0;
        play();
        //getch();
        goto start;
    case '2' :
        cleardevice();
        instruction();
        getch();
        goto start;
    case '4' :
        cleardevice();
        cradit();
        getch();
        goto start;
    case '5' :
        cleardevice();
        dedicated_to();
        getch();
        goto start;
    case '6' :
        exit(0);
    case '3' :
        cleardevice();
        hs();
        getch();
        goto start;
    default :
        goto start;

    }
    closegraph();
    return 0;
}
void cradit()
{
    drow_board_init();
    setcolor(LIGHTCYAN);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,1);

    outtextxy(scrLeft+10,maxScrTop+10,"All credit goes to Short time hard work");
    outtextxy(midx,maxScrTop+10+textheight("w")," & extra care of teachers");
    outtextxy(scrLeft+10,maxScrTop+10+3*textheight("w"),"Thanks to                   Because of");
    setcolor(RED);
    outtextxy(scrLeft+20,maxScrTop+10+4*textheight("w")+40,"Saleh Ahmed sir             Inspiration,care,Pressure");
    setcolor(GREEN);
    outtextxy(scrLeft+20,maxScrTop+10+5*textheight("w")+50,"Sajal Haldar sir               Idea,care,help");
    setcolor(YELLOW);
    outtextxy(scrLeft+20,maxScrTop+10+6*textheight("w")+60,"Mrinal Kanti Baowaly sir           care");
    setcolor(LIGHTGRAY);
    outtextxy(scrLeft+20,maxScrTop+10+7*textheight("w")+70,"Jamal Uddin sir             care");
    setcolor(WHITE);
    outtextxy(scrLeft+20,maxScrTop+10+15*textheight("w"),"Special Thanks to Hanif Siddiqui sir");


    /*settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
    outtextxy(midx,maxScrTop+50+2*textheight("w"),"Sajal Haldar");
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,1);
    outtextxy(scrLeft+100,maxScrTop+50+3*textheight("w"),"Lecturer .  Dept. of CSE at BSMRSTU");
    outtextxy(midx-100,midy-textheight("w"),"Created by");
    outtextxy(scrLeft+100,midy,"Tanvir Hasan");
    outtextxy(scrLeft+100,midy+textheight("w"),"Dept. of CSE at BSMRSTU");*/
}
void dedicated_to()
{

    drow_board_init();
    setcolor(RED);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
    outtextxy(scrLeft+10,midy-100,"SALEH AHMED   sir");
    setcolor(GREEN);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,1);

    outtextxy(scrLeft+20,maxScrDepth-50,"Because of his inspiration help me to complete this");
    //settextstyle(EUROPEAN_FONT,HORIZ_DIR,1);



    //settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
    //outtextxy(scrLeft+200,midy-150+textheight("w"),"MD Saleh Ahmed");
//    outt

}
void instruction()
{
    drow_board_init();
    setcolor(GREEN);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,1);
    outtextxy(scrLeft+60,midy-150,"Your challenge to save the helicopter");
    outtextxy(scrLeft+200,midy-150+textheight("w"),"from bricks");
    setcolor(LIGHTCYAN);
    outtextxy(scrLeft+60,midy,"Use upper arrow to step up");
    outtextxy(scrLeft+60,midy+textheight("w"),"Use down arrow to step down");
    outtextxy(scrLeft+60,midy+2*textheight("w"),"Use right arrow to step forward");
    outtextxy(scrLeft+60,midy+3*textheight("w"),"Use left arrow to step backward");
    outtextxy(scrLeft+60,midy+4*textheight("w"),"Use Space to push/resume");
    outtextxy(scrLeft+60,midy+5*textheight("w"),"Use ESC back to main menu from any where");
    setcolor(LIGHTBLUE);
    outtextxy(scrLeft+10,midy+8*textheight("w"),"press any key for back to main-menu");
}
void initboard()
{
    maxScrLen=getmaxx()-20;
    maxScrDepth=getmaxy()-20;
    midx=maxScrLen/2;
    midy=maxScrDepth/2;
    drow_board_init();
    setcolor(RED);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,2);
    outtextxy(midx-200,maxScrTop+5,"Welcome To" );
    int h=textheight("w");
    setcolor(YELLOW);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,4);
    outtextxy(midx-150,maxScrTop+h+20,"The Helicopter Game " );
    setcolor(WHITE);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,2);
    outtextxy(midx-200,midy-50,"Press The Number You choice" );
    setcolor(GREEN);
    outtextxy(midx,midy+textheight("w"),"1. Start Game");
    outtextxy(midx,midy+2*textheight("w"),"2. Instruction");
    outtextxy(midx,midy+3*textheight("w"),"3. High Score");
    outtextxy(midx,midy+4*textheight("w"),"4. Cradits");
    outtextxy(midx,midy+5*textheight("w"),"5. Dedicated To");
    outtextxy(midx,midy+6*textheight("w"),"6. Quit");
    return;
}
void play()
{
    p_hi=maxScrDepth/2-10;
    p_low=maxScrDepth/2+10;
    p_forwd=scrLeft+30;
    p_backwd=scrLeft;

    drow_board_GREEN();
    p_drow();
    initial_bricks_ary();
    int t1=0;

    clock_t b,d,a;
    b=clock();
    a=clock();
    d=a-1000;
    tm=clock()+10000000;
    while(tm> clock())  //also can be state conditon s<play_time
    {
        a=clock();
        if(a-d>=1000)
        {
            s++;
            d=a;
            score_board();
        }
        if(s/30)
        {
            s=0;
            t1++;
        }
        drow_brick();

        delay(10-t1);

        if(kbhit()) if(key_hit()) return;
        if(check_accident())
        {
            game_over();
            return;
        }
        clr_brick();
        score_board_clr();

    }
}

void drow_brick()
{
    minimize_x_axis(upb_area,ary_size);
    for(int i=0; i<ary_size; i++)
    {
        if(upb_area[i][0]+m >= maxScrLen)
            upper_brick(upb_area[i][0],upb_area[i][2],maxScrLen,upb_area[i][1]);
        else
            upper_brick(upb_area[i][0],upb_area[i][2],upb_area[i][0]+m,upb_area[i][1]);
    }
    minimize_x_axis(lob_area,ary_size2);
    for(int i=0; i<ary_size2; i++)
    {
        if(lob_area[i][0]+m >= maxScrLen)
            lower_brick(lob_area[i][0],lob_area[i][2],maxScrLen,lob_area[i][1]);
        else
            lower_brick(lob_area[i][0],lob_area[i][2],lob_area[i][0]+m,lob_area[i][1]);
    }
    return;

}
void clr_brick()
{
    for(int i=0; i<ary_size; i++)
    {
        if(upb_area[i][0]+m >= maxScrLen)
            upper_brick_clr(upb_area[i][0],upb_area[i][2],maxScrLen,i);
        else
            upper_brick_clr(upb_area[i][0],upb_area[i][2],upb_area[i][0]+m,i);
    }

    for(int i=0; i<ary_size2; i++)
    {
        if(lob_area[i][0]+m >= maxScrLen)
            lower_brick_clr(lob_area[i][0],lob_area[i][2],maxScrLen,i);
        else
            lower_brick_clr(lob_area[i][0],lob_area[i][2],lob_area[i][0]+m,i);
    }
    return;
}
void drow_board_GREEN()  //game box
{
    setcolor(GREEN);
    rectangle(scrLeft,maxScrTop,maxScrLen,maxScrDepth);
    setfillstyle(SOLID_FILL,GREEN );
    floodfill(scrLeft+1,maxScrTop+1,GREEN);
    return;
}

void p_clear()
{
    setcolor(GREEN);
    rectangle(p_backwd,p_hi,p_forwd,p_low);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(p_backwd+1,p_hi+1,GREEN);
    return;
}

void p_drow()
{
    setcolor(BLUE);
    rectangle(p_backwd,p_hi,p_forwd,p_low);
    setfillstyle(XHATCH_FILL,BLUE );
    floodfill(p_backwd+1,p_hi+1,BLUE);
    return;
}
void upper_brick(int x1,int rhi,int rx2,int rclor)
{
    setcolor(rclor);
    if(rx2 <=scrLeft ) return;
    if(x1<=scrLeft)
    {
        rectangle(scrLeft,rhi,rx2,maxScrTop);
        setfillstyle(HATCH_FILL,rclor);
        floodfill(scrLeft+1,rhi-1,rclor);
    }
    else
    {
        rectangle(x1,rhi,rx2,maxScrTop);
        setfillstyle(HATCH_FILL,rclor);
        floodfill(x1+1,rhi-1,rclor);
    }
    return;
}
void upper_brick_clr(int x1,int rhi,int rx2,int new_endl)
{
    if(rx2 <=scrLeft )
    {
        upb_area[new_endl][0]=maxScrLen-10;
        upb_area[new_endl][1]=rand()%12+3;//rand()% (GREEN-1)+1;
        upb_area[new_endl][2]=min_brk_height + rand()% midy + maxScrTop;

        for(int i=0; i<ary_size2; i++)
            if(upb_area[new_endl][2]+30 >=lob_area[i][2])
                if(lob_area[i][0]+m>=maxScrLen-60) upb_area[new_endl][2]-=(upb_area[new_endl][2]-lob_area[i][2]+min_div_btn_ulb);
        return;
    }
    setcolor(GREEN);
    if(x1<=scrLeft)
    {
        rectangle(scrLeft,rhi,rx2,maxScrTop);
        setfillstyle(SOLID_FILL,GREEN);
        floodfill(scrLeft+1,rhi-1,GREEN);
    }
    else
    {
        rectangle(x1,rhi,rx2,maxScrTop);
        setfillstyle(SOLID_FILL,GREEN);
        floodfill(x1+1,rhi-1,GREEN);
    }
    return;
}
void lower_brick(int x1,int rhi,int rx2,int rclor)
{
    setcolor(rclor);
    if(rx2 <=scrLeft ) return;
    if(x1<=scrLeft)
    {
        rectangle(scrLeft,rhi,rx2,maxScrDepth);
        setfillstyle(HATCH_FILL,rclor);
        floodfill(scrLeft+1,rhi+1,rclor);
    }
    else
    {
        rectangle(x1,rhi,rx2,maxScrDepth);
        setfillstyle(HATCH_FILL,rclor);
        floodfill(x1+1,rhi+1,rclor);
    }
    return;
}

void lower_brick_clr(int x1,int rhi,int rx2,int new_endl)
{
    if(rx2 <=scrLeft )
    {
        lob_area[new_endl][0]=maxScrLen-10;
        lob_area[new_endl][2]= maxScrDepth-min_brk_height-rand()% (maxScrDepth-midy) ;
        lob_area[new_endl][1]=rand()%12+3;

        for(int i=0; i<ary_size2; i++)
            if(lob_area[new_endl][2]-30 <=upb_area[i][2])
                if(upb_area[i][0]+m>=maxScrLen-60) lob_area[new_endl][2]+=(upb_area[i][2]-lob_area[new_endl][2]+min_div_btn_ulb);
        return;
    }
    setcolor(GREEN);
    if(x1<=scrLeft)
    {
        rectangle(scrLeft,rhi,rx2,maxScrDepth);
        setfillstyle(SOLID_FILL,GREEN);
        floodfill(scrLeft+1,rhi+1,GREEN);
    }
    else
    {
        rectangle(x1,rhi,rx2,maxScrDepth);
        setfillstyle(SOLID_FILL,GREEN);
        floodfill(x1+1,rhi-1,GREEN);
    }
    return;
}

int key_hit()
{
    char key=getch();
    switch (key)
    {
    case 27 :
        cleardevice();
        return 1;
    case 77 :
        if(maxScrLen-5<p_forwd)
        {
            p_clear();
            p_drow();
            return 0;
        }
        else
        {
            p_clear();
            p_forwd+=5;
            p_backwd+=5;
            p_drow();
            return 0;
        }

    case 75 :
        if(scrLeft+5>p_backwd)
        {
            p_clear();
            p_drow();
            return 0;
        }
        else
        {
            p_clear();
            p_backwd-=5;
            p_forwd-=5;
            p_drow();
            return 0;
        }

    case 72 :
        if(maxScrTop+6>p_hi)
        {
            p_clear();
            p_drow();
            return 0;
        }
        else
        {
            p_clear();
            p_hi-=5;
            p_low-=5;
            p_drow();
            return 0;
        }

    case 80 :
        if(maxScrDepth-6<p_low)
        {
            p_clear();
            p_drow();
            return 0;
        }
        else
        {
            p_clear();
            p_hi+=5;
            p_low+=5;
            p_drow();
            return 0;
        }
    case 32  :
        push_game();
        return 0;

    }
    return 0;
}
int check_accident()
{
    for(int i=0; i<ary_size; i++)
    {
        if(p_hi<=upb_area[i][2])
            if(p_forwd>=upb_area[i][0]&&p_backwd<=upb_area[i][0]+m)
                return 1;
    }
    for(int i=0; i<ary_size2; i++)
    {
        if(p_low>=lob_area[i][2])
            if(p_forwd>=lob_area[i][0]&&p_backwd<=lob_area[i][0]+m)
                return 1;
    }
    return 0;

}

void minimize_x_axis(int a[][3],int size)
{
    for(int i=0; i<size; i++)
    {
        a[i][0]--;
    }
    return;
}

void initial_bricks_ary()
{
    int distnu=100 ,distnl= 100;
    upb_area[0][0]=scrLeft+5;
    lob_area[0][0]=scrLeft+60;
    for(int i=0; i<ary_size;)
    {
        upb_area[i][1]=rand()%12+3;
        upb_area[i][2]=80+maxScrTop+20*i;
        upb_area[++i][0]=upb_area[i-1][0]+m+distnu;
    }
    for(int i=0; i<ary_size2;)
    {
        lob_area[i][1]=rand()%12+3;
        lob_area[i][2]=maxScrDepth-50-20*i;
        lob_area[++i][0]=lob_area[i-1][0]+m+distnl;
    }
    return;
}
void hs()
{
    drow_board_init();
    char msg[20];
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,2);
    sprintf(msg,"High score :  %d",hscore);
    outtextxy(midx-100,midy,msg);
    outtextxy(midx-200,midy+textheight("w")+100,"press any key for back to main-menu");

}
void game_over()
{
    setcolor(RED);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
    outtextxy(midx-200,midy-50,"GAME OVER");
    if(score>hscore) hscore=score;

    /*char msg[30];
    sprintf(msg, " Score : %d", score );*/
    int h=textheight("G");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 3);

    //outtextxy(midx-200,midy-50+h+50,"created by Md. Tanvir Hasan");
    outtextxy(midx-200,midy-50+h+10,"Press ESC back to main-menu");
    char ch;
    while((ch=getch())!=27);
    return;

}

void score_board()
{
    setcolor(WHITE);
    rectangle(midx,maxScrDepth+1,midx+40,maxScrDepth+10);
    char msg[40];
    sprintf(msg,"Score : %d",++score);
    settextstyle(TRIPLEX_SCR_FONT, HORIZ_DIR, 3);
    outtextxy(midx,maxScrDepth+2,msg);
    //setfillstyle(EMPTY_FILL,WHITE);
    //floodfill(midx+1,)
    return;
}
void score_board_clr()
{
    setcolor(BLACK);
    rectangle(midx,maxScrDepth+1,midx+40,maxScrDepth+10);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(midx+1,maxScrDepth+2,BLACK);
    return;

}
void drow_board_init()
{
    setcolor(RED);
    rectangle(scrLeft,maxScrTop,maxScrLen,maxScrDepth);
    //setfillstyle(SOLID_FILL,GREEN );
    //floodfill(scrLeft+1,maxScrTop+1,);
    return;
}

void push_game()
{
    clock_t f=clock();
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
    outtextxy(midx,midy,"PUSH");
    getch();
    cleardevice();
    drow_board_GREEN();
    p_drow();
    tm=tm+clock()-f;
}

