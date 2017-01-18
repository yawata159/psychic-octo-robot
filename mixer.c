#include <stdlib.h>
#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

const char *mus_file = "music.wav"
Mix_Music *music = NULL;

void musicDone() {
    Mix_HaltMusic();
    Mix_FreeMusic(music);
    music = NULL;

int main(){
    // error handling

    SDL_Init(SDL_INIT_AUDIO);

    Mix_OpenAudio(
        MIX_DEFAULT_FREQUENCY,
        MIX_DEFAULT_FORMAT,
        2, //num channels
        2048 //chunk size (4096)
    );

    // load
    music = Mix_LoadMUS(mus_file);
    Mix_PlayMusic(music, 0);

    // end callback
    Mix_HookMusicFinished(musicDone);

    Mix_CloseAudio();
    SDL_Quit();
    return 0;
}
