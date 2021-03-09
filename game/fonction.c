#include "header.h"

void initializer_image(Background B[])
{
int i;
u_char im[20];
SDL_Init(SDL_INIT_VIDEO);
for(i=0;i<3;i++)
{
snprintf(im,sizeof(im),"image%d.bmp",i);
B[i].niveau=i;
B[i].pos.x=0;
B[i].pos.y=0;
B[i].image=SDL_LoadBMP(im);
}
}


void initializer_song(Song S[])
{
int i;
SDL_Init(SDL_INIT_AUDIO);
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
Mix_VolumeMusic(MIX_MAX_VOLUME/2);
for(i=0;i<3;i++)
{
S[i].niveau=i;
S[i].music=Mix_LoadMUS("musique.mp3");
}
}


void initializer_button(Button bu[])
{
u_char im[20];
int i;
for (i=0;i<4;i++)
{

snprintf(im,sizeof(im),"bouton%d.png",i);
bu[i].button[0]=IMG_Load(im);
bu[i].pos.x=500;
bu[i].pos.y=380+(130*i);
bu[i].pos.w=256;
bu[i].pos.h=113;
bu[i].sonbref=Mix_LoadWAV("sonbref.wav");
}
bu[4].pos.x=500;
bu[4].pos.y=380;
bu[5].pos.x=620;
bu[5].pos.y=380;
bu[6].pos.x=1100;
bu[6].pos.y=800;
bu[0].button[1]=IMG_Load("boutonc0.png");
bu[1].button[1]=IMG_Load("boutonc1.png");
bu[2].button[1]=IMG_Load("boutonc2.png");
bu[3].button[1]=IMG_Load("boutonc3.png");
bu[4].button[0]=IMG_Load("bouton4.png");
bu[5].button[0]=IMG_Load("bouton5.png");
bu[6].button[0]=IMG_Load("bouton6.png");
}


/*void fullscreen(Background B[],Button bu[])
{

int i,j;
for(i=0;i<7;i++)
{
bu[i].pos.x=600;
bu[i].pos.y=380+(130*i);
}

for(j=0;j<3;j++)
{
B[i].pos.w=1920;
B[i].pos.h=957;
}

}*/

/*SDL_Rect affichage_texte(TTF_Font **police,SDL_Surface **text)
{
SDL_Color color= {0,0,0};
SDL_Rect pos;
pos.x=280;
pos.y=139;
TTF_Init();
(*police)=TTF_OpenFont("TIMES.ttf",65);
(*text)=TTF_RenderText_Solid((*police),"THE TOXIC PRODCASTER",color);

return pos;
}*/

void etat0(Button bu[],SDL_Surface *ecran,Background B[],SDL_Surface *text)
{
SDL_Rect pos_txt;
pos_txt.x=280;
pos_txt.y=139;
SDL_BlitSurface(B[0].image,NULL,ecran,&B[0].pos);
SDL_BlitSurface(bu[0].button[0],NULL,ecran,&bu[0].pos);
SDL_BlitSurface(bu[1].button[0],NULL,ecran,&bu[1].pos);
SDL_BlitSurface(bu[2].button[0],NULL,ecran,&bu[2].pos);
SDL_BlitSurface(text,NULL,ecran,&pos_txt);
}

void etat1(Button bu[],SDL_Surface *ecran,SDL_Surface *text)
{
SDL_Rect pos_txt;
pos_txt.x=280;
pos_txt.y=139;
SDL_BlitSurface(bu[0].button[0],NULL,ecran,&bu[1].pos);
SDL_BlitSurface(bu[1].button[0],NULL,ecran,&bu[1].pos);
SDL_BlitSurface(bu[2].button[1],NULL,ecran,&bu[2].pos);
SDL_BlitSurface(text,NULL,ecran,&pos_txt);
}


void etat2(Button bu[],SDL_Surface *ecran,SDL_Surface *text)
{
SDL_Rect pos_txt;
pos_txt.x=280;
pos_txt.y=139;
SDL_BlitSurface(bu[0].button[0],NULL,ecran,&bu[0].pos);
SDL_BlitSurface(bu[1].button[1],NULL,ecran,&bu[1].pos);
SDL_BlitSurface(bu[2].button[0],NULL,ecran,&bu[2].pos);
SDL_BlitSurface(text,NULL,ecran,&pos_txt);
}


void etat3(Button bu[],SDL_Surface *ecran,SDL_Surface *text)
{
SDL_Rect pos_txt;
pos_txt.x=280;
pos_txt.y=139;
SDL_BlitSurface(bu[0].button[1],NULL,ecran,&bu[0].pos);
SDL_BlitSurface(bu[1].button[0],NULL,ecran,&bu[1].pos);
SDL_BlitSurface(bu[2].button[0],NULL,ecran,&bu[2].pos);
SDL_BlitSurface(text,NULL,ecran,&pos_txt);
}
void click_bu0(Button bu[],SDL_Surface *ecran,Background B[])
{
SDL_BlitSurface(B[1].image,NULL,ecran,&B[1].pos);
      SDL_BlitSurface(bu[3].button[0],NULL,ecran,&bu[3].pos);
}

void click_bu1(Button bu[],SDL_Surface *ecran,Background B[])
{
SDL_BlitSurface(B[2].image,NULL,ecran,&B[2].pos);
      
      SDL_BlitSurface(bu[3].button[0],NULL,ecran,&bu[3].pos);
      SDL_BlitSurface(bu[4].button[0],NULL,ecran,&bu[4].pos);
      SDL_BlitSurface(bu[5].button[0],NULL,ecran,&bu[5].pos);
      SDL_BlitSurface(bu[6].button[0],NULL,ecran,&bu[6].pos);
}

void click_bu3(Button bu[],SDL_Surface *ecran,Background B[])
{
SDL_BlitSurface(bu[3].button[1],NULL,ecran,&bu[3].pos);
      SDL_BlitSurface(B[0].image,NULL,ecran,&B[0].pos);
}

void click_bu4(Button bu[],SDL_Surface *ecran,Background B[],int *V)
{
Mix_VolumeMusic(*V+=10);
}

void click_bu5(Button bu[],SDL_Surface *ecran,Background B[],int *V)
{
 Mix_VolumeMusic(*V-=10);
}

void click_bu6_1(Button bu[],SDL_Surface *ecran,Background B[])
{
int x_fen=1280;
      int y_fen=960;
      ecran=SDL_SetVideoMode(x_fen,y_fen,32,SDL_HWSURFACE | SDL_FULLSCREEN | SDL_DOUBLEBUF);
      SDL_BlitSurface(B[2].image,NULL,ecran,&B[2].pos);
      SDL_BlitSurface(bu[3].button[0],NULL,ecran,&bu[3].pos);
      SDL_BlitSurface(bu[4].button[0],NULL,ecran,&bu[4].pos);
      SDL_BlitSurface(bu[5].button[0],NULL,ecran,&bu[5].pos);
      SDL_BlitSurface(bu[6].button[0],NULL,ecran,&bu[6].pos);
}
void click_bu6_2(Button bu[],SDL_Surface *ecran,Background B[])
{
int x_fen=1280;
      int y_fen=868;
      ecran=SDL_SetVideoMode(x_fen,y_fen,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
      SDL_BlitSurface(B[2].image,NULL,ecran,&B[2].pos);
      SDL_BlitSurface(bu[3].button[0],NULL,ecran,&bu[3].pos);
      SDL_BlitSurface(bu[4].button[0],NULL,ecran,&bu[4].pos);
      SDL_BlitSurface(bu[5].button[0],NULL,ecran,&bu[5].pos);
      SDL_BlitSurface(bu[6].button[0],NULL,ecran,&bu[6].pos);



}


