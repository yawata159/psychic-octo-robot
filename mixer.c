#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_mixer.h>

static const char *mus_file = "africa-toto.wav";

int main(){
    // error handling

    SDL_Init(SDL_INIT_AUDIO);
    Mix_Init(MIX_INIT_MP3);

    Mix_OpenAudio(
        MIX_DEFAULT_FREQUENCY,
        MIX_DEFAULT_FORMAT,
        2, //num channels
        2048 //chunk size (4096)
    );

    // load
    Mix_Music *music =  Mix_LoadMUS(mus_file);
    Mix_PlayMusic(music, 1);

    while (!SDL_QuitRequested()) {
        SDL_Delay(250);
    }

    // end callback
    Mix_HaltMusic();
    Mix_FreeMusic(music);

    Mix_CloseAudio();
    SDL_Quit();
    return 0;
}
