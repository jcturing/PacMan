#include "Sound.h"

void loadSound(ALLEGRO_SAMPLE * &sound, std::string directory) {
	sound = al_load_sample(directory.c_str());
}

void loadSong(ALLEGRO_SAMPLE * &song, std::string directory, ALLEGRO_SAMPLE_INSTANCE * &songInstance, playmodeType playmode) {
	ALLEGRO_PLAYMODE al_playmode;

	switch (playmode) {
	case once: al_playmode = ALLEGRO_PLAYMODE_ONCE; break;
	case loop: al_playmode = ALLEGRO_PLAYMODE_LOOP; break;
	case bidir: al_playmode = ALLEGRO_PLAYMODE_BIDIR;
	}
	song = al_load_sample(directory.c_str());
	songInstance = al_create_sample_instance(song);
	al_set_sample_instance_playmode(songInstance, al_playmode);
	al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());
}

void playSound(ALLEGRO_SAMPLE *sound, playmodeType playmode, float volume, float pan, float speed) {
	ALLEGRO_PLAYMODE al_playmode;

	switch (playmode) {
	case once: al_playmode = ALLEGRO_PLAYMODE_ONCE; break;
	case loop: al_playmode = ALLEGRO_PLAYMODE_LOOP; break;
	case bidir: al_playmode = ALLEGRO_PLAYMODE_BIDIR;
	}
	al_play_sample(sound, volume, pan, speed, al_playmode, 0);
}

void playSong(ALLEGRO_SAMPLE_INSTANCE *songInstance) {
	al_play_sample_instance(songInstance);
}

void stopSong(ALLEGRO_SAMPLE_INSTANCE *songInstance) {
	al_stop_sample_instance(songInstance);
}

void destroySound(ALLEGRO_SAMPLE * &soundeffect) {
	al_destroy_sample(soundeffect);
	soundeffect = nullptr;
}

void destroySong(ALLEGRO_SAMPLE * &song, ALLEGRO_SAMPLE_INSTANCE * &songInstance) {
	al_destroy_sample(song);
	al_destroy_sample_instance(songInstance);
	song = nullptr;
	songInstance = nullptr;
}