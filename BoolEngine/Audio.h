#ifndef AUDIO_H
#define	AUDIO_H

//Allegro libraries
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

//Other libraries needed
#include <string>

/* 
*  This is the audio library. Everything related with the audio 
*  will be programmed here. 
*
*  Keep in mind the difference between sound and song, being the
*  first one considered as a soundEffect that might be played when
*  certain circumstances occurs and a song to be the music played
*  in the background of the game.
*/

//Types of playmodes.
enum playmodeType{ once, loop, bidir };

//Loads a sound. | PARAMETERS: Variable, directory of the sound file.
void loadSound(ALLEGRO_SAMPLE * &sound, std::string directory);
//Loads a song | PARAMETERS: Song, directory, instance, playmode (once, loop, bidir).
void loadSong(ALLEGRO_SAMPLE * &song, std::string directory, ALLEGRO_SAMPLE_INSTANCE * &songInstance, playmodeType playmode);
//Plays a sound | PARAMETERS: Sound, playmode (once/loop/birir), volume, pan (headphones side), speed.
void playSound(ALLEGRO_SAMPLE *sound, playmodeType playmode, float volume = 1.0, float pan = 0.0, float speed = 1.0);
//Plays a song | PARAMETERS: Song.
void playSong(ALLEGRO_SAMPLE_INSTANCE *songInstance);
//Stops a song | PARAMETERS: Song.
void stopSong(ALLEGRO_SAMPLE_INSTANCE *songInstance);
//Destroys and frees the memmory and resources used by the sound. Also lets the pointer to nullptr | PARAMETERS: Sound.
void destroySound(ALLEGRO_SAMPLE * &soundeffect);
//Destroys and frees the memmory and resources used by the song. Also lets the pointer to nullptr | PARAMETERS: Song.
void destroySong(ALLEGRO_SAMPLE * &song, ALLEGRO_SAMPLE_INSTANCE * &songInstance);

#endif

