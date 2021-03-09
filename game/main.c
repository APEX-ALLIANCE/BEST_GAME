#include "header.h"
int main(int argc,char **argv)
{
int i,k=0,t=0,x_fen=1280,y_fen=868;
int sound=0;
SDL_Surface *ecran;
SDL_Surface *text;
Background B[3];
Song S[3];
int done=1;
int V=MIX_MAX_VOLUME/2;
SDL_Event event;
Button bu[7];
TTF_Font *police = NULL;
SDL_Color color= {255,255,255};
int i_pos=0;
int e;


ecran=SDL_SetVideoMode(x_fen,y_fen,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_WM_SetCaption("EA SPORTS(HET FLOUSK)",NULL);
initializer_image(B);
initializer_song(S);
initializer_button(bu);
TTF_Init();
police=TTF_OpenFont("TIMES.ttf",65);
text=TTF_RenderText_Solid(police,"THE TOXIC PRODCASTER",color);

SDL_WM_SetIcon(IMG_Load("icon.png"),NULL);


Mix_PlayMusic(S[0].music,-1);

while(done)
{
    int i,x,y;
if(k==0)
{
if(i_pos==0)
etat0(bu,ecran,B,text);
if(i_pos==1)
etat1(bu,ecran,text);
else if(i_pos==2)
etat2(bu,ecran,text);
else if(i_pos==3)
etat3(bu,ecran,text);
}
  while(SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      case SDL_QUIT:
      done=0;
      break;
      case SDL_MOUSEMOTION:
      x= event.motion.x;
      y= event.motion.y;

      if (k==0)
       {

  i=0;
while(i<3&&!(x>bu[i].pos.x && x<bu[i].pos.x+bu[i].pos.w && y>bu[i].pos.y && y<bu[i].pos.y+bu[i].pos.h))
i++;

      if(i<3) 
     {
      SDL_BlitSurface(bu[i].button[1],NULL,ecran,&bu[i].pos);
      sound=1;
      }
      else
{
for(i=0;i<3;i++)
      SDL_BlitSurface(bu[i].button[0],NULL,ecran,&bu[i].pos);
     sound=0;
}//endof else

}//endof if k
      else if (k==2)
{
if(x>bu[3].pos.x && x<bu[3].pos.x+bu[3].pos.w && y>bu[3].pos.y && y<bu[3].pos.y+bu[3].pos.h)
{
SDL_BlitSurface(bu[3].button[1],NULL,ecran,&bu[3].pos);
sound=1;
}  
      else
{
SDL_BlitSurface(bu[3].button[0],NULL,ecran,&bu[3].pos);
sound=0;
}
if(x>bu[6].pos.x && x<bu[6].pos.x+bu[6].pos.w && y>bu[6].pos.y && y<bu[6].pos.y+bu[6].pos.h)
{
SDL_BlitSurface(bu[6].button[1],NULL,ecran,&bu[6].pos);
sound=1;
}  
      else
{
SDL_BlitSurface(bu[6].button[0],NULL,ecran,&bu[6].pos);
sound=0;
}
}//endof else if k=2
else
{
if(x>bu[3].pos.x && x<bu[3].pos.x+bu[3].pos.w && y>bu[3].pos.y && y<bu[3].pos.y+bu[3].pos.h)
{
SDL_BlitSurface(bu[3].button[1],NULL,ecran,&bu[3].pos);
sound=1;
}  
      else
{
SDL_BlitSurface(bu[3].button[0],NULL,ecran,&bu[3].pos);
sound=0;
}
}
if(sound==1)
{
      Mix_PlayChannel(2,bu[2].sonbref,0);
      sound=0;
}
      break;
//break mousemotion

      case SDL_MOUSEBUTTONDOWN:
      x= event.motion.x;
      y= event.motion.y;
      if (x>bu[2].pos.x && x<bu[2].pos.x+bu[2].pos.w && y>bu[2].pos.y && y<bu[2].pos.y+bu[2].pos.h &&        event.button.button==SDL_BUTTON_LEFT && k==0)
      {
      done=0;
      Mix_PlayChannel(-1,bu[2].sonbref,0);
      }//endof if
      else if (x>bu[0].pos.x && x<bu[0].pos.x+bu[0].pos.w && y>bu[0].pos.y && y<bu[0].pos.y+bu[0].pos.h &&        event.button.button==SDL_BUTTON_LEFT && k==0)
      {
      click_bu0(bu,ecran,B);
      k=1;
      }
      else if (x>bu[1].pos.x && x<bu[1].pos.x+bu[1].pos.w && y>bu[1].pos.y && y<bu[1].pos.y+bu[1].pos.h &&        event.button.button==SDL_BUTTON_LEFT && k==0)
      {
      click_bu1(bu,ecran,B);
     k=2;
      }
     else if (x>bu[3].pos.x && x<bu[3].pos.x+bu[3].pos.w && y>bu[3].pos.y && y<bu[3].pos.y+bu[3].pos.h &&        event.button.button==SDL_BUTTON_LEFT && (k==2 || k==1))
      {
      click_bu3(bu,ecran,B);
      k=0;
      
      }
     
     else if (x>bu[4].pos.x && x<bu[4].pos.x+bu[4].pos.w && y>bu[4].pos.y && y<bu[4].pos.y+bu[4].pos.h &&        event.button.button==SDL_BUTTON_LEFT && k==2)
      {
      click_bu4(bu,ecran,B,&V);
      
      }
      else if (x>bu[5].pos.x && x<bu[5].pos.x+bu[5].pos.w && y>bu[5].pos.y && y<bu[5].pos.y+bu[5].pos.h &&        event.button.button==SDL_BUTTON_LEFT && k==2)
      {
      click_bu5(bu,ecran,B,&V);
      }
      else if (x>bu[6].pos.x && x<bu[6].pos.x+bu[6].pos.w && y>bu[6].pos.y && y<bu[6].pos.y+bu[6].pos.h &&        event.button.button==SDL_BUTTON_LEFT && k==2 && t==0)
      {
      click_bu6_1(bu,ecran,B);
      t=1;
      
       }
      else if (x>bu[6].pos.x && x<bu[6].pos.x+bu[6].pos.w && y>bu[6].pos.y && y<bu[6].pos.y+bu[6].pos.h &&        event.button.button==SDL_BUTTON_LEFT && k==2 && t==1)
      {
      click_bu6_2(bu,ecran,B);
      t=0;
      
      }     
      break;
//break mousebuttondown
     case SDL_KEYDOWN:    
switch(event.key.keysym.sym)
{
case SDLK_ESCAPE:
done=0;
break;
case SDLK_p:
if(Mix_PausedMusic()==1)
Mix_ResumeMusic();//end of if
else
Mix_PauseMusic();
break;
case SDLK_j:
break;
case SDLK_UP:
if(k==0)
{
e=0;
if(i_pos==0 && e==0)
{
i_pos=1;
e=1;
}
else if(i_pos==1 && e==0)
{
i_pos=2;
e=1;
}
else if(i_pos==2 && e==0)
{
i_pos=3;
e=1;
}
else if(i_pos==3 && e==0)
{
i_pos=0;
e=1;
}
}
break;
case SDLK_DOWN:
if(k==0)
{
e=0;
if(i_pos==0 && e==0)
{
i_pos=1;
e=1;
}
else if(i_pos==1 && e==0)
{
i_pos=3;
e=1;
}
else if(i_pos==2 && e==0)
{
i_pos=1;
e=1;
}
else if(i_pos==3 && e==0)
{
i_pos=2;
e=1;
}
}
break;
case SDLK_SPACE:
if(k==0)
{
if(i_pos==0)
{

}
else if(i_pos==1 )
{
done=0;
}
else if(i_pos==2 )
{
SDL_BlitSurface(B[2].image,NULL,ecran,&B[2].pos);
      
      SDL_BlitSurface(bu[3].button[0],NULL,ecran,&bu[3].pos);
      SDL_BlitSurface(bu[4].button[0],NULL,ecran,&bu[4].pos);
      SDL_BlitSurface(bu[5].button[0],NULL,ecran,&bu[5].pos);
      SDL_BlitSurface(bu[6].button[0],NULL,ecran,&bu[6].pos);
     k=2;SDL_BlitSurface(B[2].image,NULL,ecran,&B[2].pos);
      
      SDL_BlitSurface(bu[3].button[0],NULL,ecran,&bu[3].pos);
      SDL_BlitSurface(bu[4].button[0],NULL,ecran,&bu[4].pos);
      SDL_BlitSurface(bu[5].button[0],NULL,ecran,&bu[5].pos);
      SDL_BlitSurface(bu[6].button[0],NULL,ecran,&bu[6].pos);
     k=2;
}
else if(i_pos==3 )
{
SDL_BlitSurface(B[1].image,NULL,ecran,&B[1].pos);
      SDL_BlitSurface(bu[3].button[0],NULL,ecran,&bu[3].pos);
      
      k=1;
}
}
break;
}//end of switch keydown
}//end of switch event_type

SDL_Flip(ecran);

}//end of while pollEvent

}//endof while

for (i=0;i<3;i++)
{
SDL_FreeSurface(bu[i].button[0]);
Mix_FreeChunk(bu[i].sonbref);
SDL_FreeSurface(bu[i].button[1]);
SDL_FreeSurface(B[i].image);
Mix_FreeMusic(S[i].music);
}
SDL_FreeSurface(bu[4].button[0]);
SDL_FreeSurface(bu[5].button[0]);
SDL_FreeSurface(bu[6].button[0]);
SDL_FreeSurface(bu[3].button[0]);
SDL_FreeSurface(bu[3].button[1]);
SDL_FreeSurface(text);
TTF_CloseFont(police);
Mix_CloseAudio();
TTF_Quit();
SDL_Quit();
return 0;
}
