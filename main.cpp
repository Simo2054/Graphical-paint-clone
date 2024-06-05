#include <iostream>
#include <graphics.h>
#include <cstring>
#include <windows.h>
#include <mmsystem.h>
#include <fstream>

using namespace std;

int Ww=1500,Hw=1000;

void graphic_window()
{
    initwindow(Ww,Hw,"Paint.exe",400,10);
}

int space=10;
int w_left_bar=200;
int h_left_bar=Hw-2*space;//980
int w_down_bar=Ww-3*space-w_left_bar;//1270
int h_down_bar=200;
int canvas_max_height=Hw-h_down_bar-3*space; //770
int canvas_max_width=Ww-w_left_bar-3*space; //1270
int smol_buttons_height=h_down_bar/2;//100
int smol_buttons_width=(w_down_bar/4-3*space)/2;//143
int tools_height=(h_down_bar-4*space)/2;//80
int tools_width=w_down_bar/8-4*space;//118
int colors_width=(w_down_bar/2)/6;//105
int colors_height=h_down_bar/2;//100

void display_buttons()
{
    readimagefile("buttons/background.jpg", space, space, space+w_left_bar, Hw-space);//left bar
    readimagefile("buttons/background.jpg", 2*space+w_left_bar, 2*space+canvas_max_height, 2*space+w_left_bar+w_down_bar, 2*space+canvas_max_height+h_down_bar);//down bar
    readimagefile("buttons/new_canvas_button.jpg", 2*space, 4*space, w_left_bar, 13*space);//new canvas button
    readimagefile("buttons/save_canvas_button.jpg",2*space, 16*space, w_left_bar, 25*space);//save canvas button
    readimagefile("buttons/0.jpg",2*space+w_left_bar+w_down_bar/2, 2*space+canvas_max_height, 2*space+w_left_bar+w_down_bar/2, Hw-space);//half separation
    //readimagefile("buttons/0.jpg",2*space+w_left_bar+3*w_down_bar/4, 2*space+canvas_max_height, 2*space+w_left_bar+3*w_down_bar/4, Hw-space);// 3/4 separation
    readimagefile("buttons/0.jpg",2*space+w_left_bar+5*w_down_bar/8, 2*space+canvas_max_height, 2*space+w_left_bar+5*w_down_bar/8, Hw-space);// 5/8 separation
    readimagefile("buttons/pencil_tool.jpg", 4*space+w_left_bar+4*w_down_bar/8, 3*space+canvas_max_height, 4*space+w_left_bar+4*w_down_bar/8+tools_width, 3*space+canvas_max_height+tools_height);
    readimagefile("buttons/bucket_tool.jpg", 4*space+w_left_bar+4*w_down_bar/8, 5*space+canvas_max_height+tools_height, 4*space+w_left_bar+4*w_down_bar/8+tools_width, 5*space+canvas_max_height+2*tools_height);
    readimagefile("buttons/used_color_box.jpg", space+2*space, 2*space+canvas_max_height, w_left_bar-2*space+space, Hw-space);//used color box

    //readimagefile("buttons/0.jpg", space+2*space+7, 2*space+canvas_max_height+84, w_left_bar-2*space+space-7, Hw-space-7);
    //readimagefile("buttons/canvas.jpg", 2*space+w_left_bar, space, 2*space+w_left_bar+canvas_max_width, space+canvas_max_height);//canvas
}

void display_colors()
{
    readimagefile("colors/1.jpg", 2*space+w_left_bar, 2*space+canvas_max_height, 2*space+w_left_bar+colors_width, 2*space+canvas_max_height+colors_height);
    readimagefile("colors/2.jpg", 2*space+w_left_bar+colors_width, 2*space+canvas_max_height, 2*space+w_left_bar+2*colors_width, 2*space+canvas_max_height+colors_height);
    readimagefile("colors/3.jpg", 2*space+w_left_bar+2*colors_width, 2*space+canvas_max_height, 2*space+w_left_bar+3*colors_width, 2*space+canvas_max_height+colors_height);
    readimagefile("colors/4.jpg", 2*space+w_left_bar+3*colors_width, 2*space+canvas_max_height, 2*space+w_left_bar+4*colors_width, 2*space+canvas_max_height+colors_height);
    readimagefile("colors/5.jpg", 2*space+w_left_bar+4*colors_width, 2*space+canvas_max_height, 2*space+w_left_bar+5*colors_width, 2*space+canvas_max_height+colors_height);
    readimagefile("colors/6.jpg", 2*space+w_left_bar+5*colors_width, 2*space+canvas_max_height, 2*space+w_left_bar+6*colors_width, 2*space+canvas_max_height+colors_height);
//---------------------------
    readimagefile("colors/7.jpg", 2*space+w_left_bar, 2*space+canvas_max_height+colors_height, 2*space+w_left_bar+colors_width, 2*space+canvas_max_height+2*colors_height);
    readimagefile("colors/8.jpg", 2*space+w_left_bar+colors_width, 2*space+canvas_max_height+colors_height, 2*space+w_left_bar+2*colors_width, 2*space+canvas_max_height+2*colors_height);
    readimagefile("colors/9.jpg", 2*space+w_left_bar+2*colors_width, 2*space+canvas_max_height+colors_height, 2*space+w_left_bar+3*colors_width, 2*space+canvas_max_height+2*colors_height);
    readimagefile("colors/10.jpg", 2*space+w_left_bar+3*colors_width, 2*space+canvas_max_height+colors_height, 2*space+w_left_bar+4*colors_width, 2*space+canvas_max_height+2*colors_height);
    readimagefile("colors/11.jpg", 2*space+w_left_bar+4*colors_width, 2*space+canvas_max_height+colors_height, 2*space+w_left_bar+5*colors_width, 2*space+canvas_max_height+2*colors_height);
    readimagefile("colors/12.jpg", 2*space+w_left_bar+5*colors_width, 2*space+canvas_max_height+colors_height, 2*space+w_left_bar+6*colors_width, 2*space+canvas_max_height+2*colors_height);
}

void graphic_start()
{
    graphic_window();
    display_buttons();
    display_colors();
}

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int color_number=0;
//11 7     20 10
int nr_pixels_width=11;
int nr_pixels_height=7;
int pixel_width=canvas_max_width/nr_pixels_width;
int pixel_height=canvas_max_height/nr_pixels_height;

bool canvas_off=1;
bool pencil_available=1;
bool bucket_available=1;
int matrix[25][25];
int saved[25][25];

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void generate_matrix()
{
    ofstream foff("matrix_ini.txt");
    foff<<nr_pixels_height<<" "<<nr_pixels_width;
    foff<<endl;
    for(int i=0; i<=nr_pixels_height+1; i++)
    {
        for(int j=0; j<=nr_pixels_width+1; j++)
        {
            matrix[i][j]=0;
            matrix[0][j]=99;
            matrix[i][0]=99;
            matrix[nr_pixels_height+1][j]=99;
            matrix[i][nr_pixels_width+1]=99;
            foff<<matrix[i][j]<<" ";
        }
        foff<<endl;
    }

}

void define_matrix()
{
    ofstream foff("matrix_ini.txt");
    foff<<nr_pixels_height<<" "<<nr_pixels_width;
    foff<<endl;
    for(int s=0; s<=nr_pixels_height+1; s++)
    {
        for(int t=0; t<=nr_pixels_width+1; t++)
        {
            foff<<matrix[s][t]<<" ";
        }
        foff<<endl;
    }
}


void choose_color()
{
    int W, H;
    while(color_number==0)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, W, H);
            for(int i=1; i<=2; i++)
                for(int j=1; j<=6; j++)
                    if(((W>=2*space+w_left_bar+(j-1)*colors_width)&&(W<=2*space+w_left_bar+j*colors_width))&&((H>=2*space+canvas_max_height+(i-1)*colors_height)&&(H<=2*space+canvas_max_height+i*colors_height)))
                    {
                        color_number=(i-1)*6+j;
                    }
        }
    }
}

void activate_color(int nr, int w_top, int h_top, int w_bot, int h_bot)
{
    char sir[255]="colors/";
    char s[10];
    itoa(nr,s,10);
    strcat(sir,s);
    strcat(sir,".jpg");
    readimagefile(sir,w_top,h_top,w_bot,h_bot);
}

void start_tool()
{
    int W, H;
    while(pencil_available==1 && bucket_available==1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, W, H);
            if(((W>=4*space+w_left_bar+4*w_down_bar/8)&&(W<=4*space+w_left_bar+4*w_down_bar/8+tools_width))&&((H>=3*space+canvas_max_height)&&(H<=3*space+canvas_max_height+tools_height)))///select pencil tool
            {
                readimagefile("buttons/pencil_tool_pressed.jpg", 4*space+w_left_bar+4*w_down_bar/8, 3*space+canvas_max_height, 4*space+w_left_bar+4*w_down_bar/8+tools_width, 3*space+canvas_max_height+tools_height);
                /// cout<<"pencil";
                bucket_available=1;
                pencil_available=0;

                color_number=0;
                choose_color();
                activate_color(color_number, space+2*space+7, 2*space+canvas_max_height+84, w_left_bar-2*space+space-7, Hw-space-7);
            }
            else if(((W>=4*space+w_left_bar+4*w_down_bar/8)&&(W<=4*space+w_left_bar+4*w_down_bar/8+tools_width))&&((H>=5*space+canvas_max_height+tools_height)&&(H<=5*space+canvas_max_height+2*tools_height)))///select bucket tool
            {
                readimagefile("buttons/bucket_tool_pressed.jpg", 4*space+w_left_bar+4*w_down_bar/8, 5*space+canvas_max_height+tools_height, 4*space+w_left_bar+4*w_down_bar/8+tools_width, 5*space+canvas_max_height+2*tools_height);
                ///cout<<"bucket";
                bucket_available=0;
                pencil_available=1;

                color_number=0;
                choose_color();
                activate_color(color_number, space+2*space+7, 2*space+canvas_max_height+84, w_left_bar-2*space+space-7, Hw-space-7);
            }
        }
    }
}

int L[10]= {-1, 0, 1, 0};
int C[10]= {0, -1, 0, 1};

void filling(int x, int y, int k)
{
    if(matrix[x][y]==0 || matrix[x][y]==6)
    {
        matrix[x][y]=k;
        for(int m=0; m<=3; m++)
        {
            activate_color(color_number, 2*space+w_left_bar+(y-1)*pixel_width, space+(x-1)*pixel_height, 2*space+w_left_bar+y*pixel_width, space+x*pixel_height);
            filling(x+L[m], y+C[m], k);
        }
    }
}

void fill_space()
{
    int W, H;
    while(color_number!=0 && bucket_available==0)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, W, H);
            for(int i=1; i<=nr_pixels_height; i++)
                for(int j=1; j<=nr_pixels_width; j++)
                    if(((W>=2*space+w_left_bar+(j-1)*pixel_width)&&(W<=2*space+w_left_bar+j*pixel_width))&&((H>=space+(i-1)*pixel_height)&&(H<=space+i*pixel_height)))///fill pixels
                    {
                        filling(i,j,color_number);

                        define_matrix();

                        //cout<<"fill";
                    }
                    else if(((W>=2*space+w_left_bar)&&(W<=2*space+w_left_bar+6*colors_width))&&((H>=2*space+canvas_max_height)&&(H<=2*space+canvas_max_height+2*colors_height)))///select new color
                    {
                        for(int p=1; p<=2; p++)
                            for(int q=1; q<=6; q++)
                                if(((W>=2*space+w_left_bar+(q-1)*colors_width)&&(W<=2*space+w_left_bar+q*colors_width))&&((H>=2*space+canvas_max_height+(p-1)*colors_height)&&(H<=2*space+canvas_max_height+p*colors_height)))
                                {
                                    color_number=(p-1)*6+q;
                                    activate_color(color_number, space+2*space+7, 2*space+canvas_max_height+84, w_left_bar-2*space+space-7, Hw-space-7);//in the used color box
                                }

                    }
                    else if(((W>=4*space+w_left_bar+4*w_down_bar/8)&&(W<=4*space+w_left_bar+4*w_down_bar/8+tools_width))&&((H>=3*space+canvas_max_height)&&(H<=3*space+canvas_max_height+tools_height)))///select pencil tool
                    {
                        readimagefile("buttons/bucket_tool.jpg", 4*space+w_left_bar+4*w_down_bar/8, 5*space+canvas_max_height+tools_height, 4*space+w_left_bar+4*w_down_bar/8+tools_width, 5*space+canvas_max_height+2*tools_height);
                        color_number=0;
                        readimagefile("buttons/background.jpg", space+2*space+7, 2*space+canvas_max_height+84, w_left_bar-2*space+space-7, Hw-space-7);
                        pencil_available=1;
                        bucket_available=1;
                    }
        }
    }
}



void draw_pixel()
{
    int W, H;
    while(color_number!=0 && pencil_available==0)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, W, H);
            for(int i=1; i<=nr_pixels_height; i++)
            {
                for(int j=1; j<=nr_pixels_width; j++)
                    if(((W>=2*space+w_left_bar+(j-1)*pixel_width)&&(W<=2*space+w_left_bar+j*pixel_width))&&((H>=space+(i-1)*pixel_height)&&(H<=space+i*pixel_height)))///draw pixel
                    {

                        matrix[i][j]=color_number;
                        activate_color(color_number, 2*space+w_left_bar+(j-1)*pixel_width, space+(i-1)*pixel_height, 2*space+w_left_bar+j*pixel_width, space+i*pixel_height );
                        define_matrix();
                       /// cout<<"draw";
                    }
                    else if(((W>=2*space+w_left_bar)&&(W<=2*space+w_left_bar+6*colors_width))&&((H>=2*space+canvas_max_height)&&(H<=2*space+canvas_max_height+2*colors_height)))///select new color
                    {
                        for(int p=1; p<=2; p++)
                        {
                            for(int q=1; q<=6; q++)
                                if(((W>=2*space+w_left_bar+(q-1)*colors_width)&&(W<=2*space+w_left_bar+q*colors_width))&&((H>=2*space+canvas_max_height+(p-1)*colors_height)&&(H<=2*space+canvas_max_height+p*colors_height)))
                                {
                                    color_number=(p-1)*6+q;
                                    activate_color(color_number, space+2*space+7, 2*space+canvas_max_height+84, w_left_bar-2*space+space-7, Hw-space-7);//in the used color box
                                }
                        }
                        break;
                    }

                    else if(((W>=4*space+w_left_bar+4*w_down_bar/8)&&(W<=4*space+w_left_bar+4*w_down_bar/8+tools_width))&&((H>=5*space+canvas_max_height+tools_height)&&(H<=5*space+canvas_max_height+2*tools_height)))///select bucket tool
                    {
                        readimagefile("buttons/pencil_tool.jpg", 4*space+w_left_bar+4*w_down_bar/8, 3*space+canvas_max_height, 4*space+w_left_bar+4*w_down_bar/8+tools_width, 3*space+canvas_max_height+tools_height);
                        color_number=0;
                        readimagefile("buttons/background.jpg", space+2*space+7, 2*space+canvas_max_height+84, w_left_bar-2*space+space-7, Hw-space-7);
                        pencil_available=1;
                        bucket_available=1;
                    }
            }

        }
    }
}


void canvas_button()
{
    int W, H;
    while(canvas_off==1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, W, H);
            if(((W>=2*space)&&(W<=w_left_bar))&&((H>=4*space)&&(H<=13*space)))///new canvas
            {
                readimagefile("buttons/new_canvas_button_pressed.jpg", 2*space, 4*space, w_left_bar, 13*space);
                for(int i=1; i<=nr_pixels_height; i++)
                    for(int j=1; j<=nr_pixels_width; j++)
                        readimagefile("buttons/canvas.jpg", 2*space+w_left_bar+(j-1)*pixel_width, space+(i-1)*pixel_height, 2*space+w_left_bar+j*pixel_width+1, space+i*pixel_height+1);
                generate_matrix();
                canvas_off=0;
            }
            else if(((W>=2*space)&&(W<=w_left_bar))&&((H>=16*space)&&(H<=25*space)))///load saved canvas
            {
                readimagefile("buttons/save_canvas_button_pressed.jpg",2*space, 16*space, w_left_bar, 25*space);
                ifstream fin("matrix_ini.txt");
                fin>>nr_pixels_height>>nr_pixels_width;
                for(int i=0; i<=nr_pixels_height+1; i++)
                    for(int j=0; j<=nr_pixels_width+1; j++)
                    {
                        fin>>saved[i][j];
                        if(saved[i][j]==0)
                            saved[i][j]=6;
                        matrix[i][j]=saved[i][j];
                        activate_color(saved[i][j], 2*space+w_left_bar+(j-1)*pixel_width, space+(i-1)*pixel_height, 2*space+w_left_bar+j*pixel_width, space+i*pixel_height);
                        saved[i][j]=matrix[i][j];
                        canvas_off=0;
                    }

            }
        }
    }
}


void use_tools()
{
    while(canvas_off==0)
    {
        start_tool();
        draw_pixel();
        fill_space();
    }
}

void how_to_start()
{
    if(canvas_off==1)
    {
        canvas_button();
    }
}

int main()
{
    graphic_start();
    how_to_start();
    use_tools();
    delay(10000);
    return 0;
}
