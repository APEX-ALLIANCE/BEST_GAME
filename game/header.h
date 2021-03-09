#ifndef HEADER_H_
#define HEADER_H_
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
SDL_Surface *image;
SDL_Rect pos;
int niveau;
}Background;
typedef struct{
Mix_Music *music;
int niveau;
}Song;
typedef struct {
SDL_Surface *button[2];
SDL_Rect pos;
Mix_Chunk *sonbref;
}Button;

void initializer_image(Background B[]);
void initializer_song(Song S[]);
void initializer_button(Button bu[]);
/*void fullscreen(Background B[],Button bu[]);*/
void click_bu0(Button bu[],SDL_Surface *ecran,Background B[]);
void click_bu1(Button bu[],SDL_Surface *ecran,Background B[]);
void click_bu3(Button bu[],SDL_Surface *ecran,Background B[]);
void click_bu4(Button bu[],SDL_Surface *ecran,Background B[],int *V);
void click_bu5(Button bu[],SDL_Surface *ecran,Background B[],int *V);
void click_bu6_1(Button bu[],SDL_Surface *ecran,Background B[]);
void click_bu6_2(Button bu[],SDL_Surface *ecran,Background B[]);

void etat0(Button bu[],SDL_Surface *ecran,Background B[],SDL_Surface *text);
/*SDL_Rect affichage_texte(TTF_Font **police,SDL_Surface **text);*/
void etat1(Button bu[],SDL_Surface *ecran,SDL_Surface *text);
void etat2(Button bu[],SDL_Surface *ecran,SDL_Surface *text);
void etat3(Button bu[],SDL_Surface *ecran,SDL_Surface *text);

#endif
