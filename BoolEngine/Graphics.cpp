#include "Graphics.h"

void loadSprite(ALLEGRO_BITMAP * &image, const std::string file) {	
	ALLEGRO_PATH * path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	
	al_append_path_component(path, "Resources");
	al_append_path_component(path, "Sprites");
	al_change_directory(al_path_cstr(path, '/'));
	al_destroy_path(path);								//Until here modified to change the current working directory

	image = al_load_bitmap(file.c_str());
}

void loadSprite(std::vector<ALLEGRO_BITMAP*> &tImage, std::string directory, int width_num, int height_num) {
	ALLEGRO_PATH * path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(path, "Resources");
	al_append_path_component(path, "Animations");
	al_change_directory(al_path_cstr(path, '/'));
	al_destroy_path(path);

	tImage.push_back(al_load_bitmap(directory.c_str()));
	int width = al_get_bitmap_width(tImage[0]) / width_num;
	int height = al_get_bitmap_height(tImage[0]) / height_num;
	for (int i = 0; i < height_num; i++) {
		for (int j = 0; j < width_num; j++) {
			tImage.push_back(al_create_sub_bitmap(tImage[0], j * width, i * height, width, height));
		}
	}
}

void loadSprite(std::vector<ALLEGRO_BITMAP*> &tImage, std::string directory) {

}

bool saveSprite(ALLEGRO_BITMAP * &image, std::string directory) {
	return al_save_bitmap(directory.c_str(), image);
}

void drawSprite(ALLEGRO_BITMAP *image, float posx, float posy) {
	al_draw_bitmap(image, posx, posy, NULL);
}

void drawSprite(ALLEGRO_BITMAP *image, float posx, float posy, ALLEGRO_COLOR tint) {
	al_draw_tinted_bitmap(image, tint, posx, posy, NULL);
}

void drawSprite(ALLEGRO_BITMAP *image, float posx, float posy, float centerx, float centery, float angle) {
	al_draw_rotated_bitmap(image, centerx, centery, posx, posy, angle, NULL);
}

void drawSprite(ALLEGRO_BITMAP *image, float posx, float posy, float swidth, float sheight) 
{
	float width, height;

	width = swidth * al_get_bitmap_width(image);
	height = sheight * al_get_bitmap_height(image);
	al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), posx, posy, width, height, NULL);
}

void drawSprite(ALLEGRO_BITMAP *image, float posx, float posy, ALLEGRO_COLOR tint, float centerx, float centery, float angle) {
	al_draw_tinted_rotated_bitmap(image, tint, centerx, centery, posx, posy, angle, NULL);
}

void drawSprite(ALLEGRO_BITMAP *image, float posx, float posy, ALLEGRO_COLOR tint, float swidth, float sheight){
	float width, height;
	width = swidth * al_get_bitmap_width(image);
	height = sheight * al_get_bitmap_height(image);
	al_draw_tinted_scaled_bitmap(image, tint, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), posx, posy, width, height, NULL);
}

void drawSprite(ALLEGRO_BITMAP *image, float posx, float posy, float centerx, float centery, float angle, float swidth, float sheight){
	al_draw_scaled_rotated_bitmap(image, centerx, centery, posx, posy, swidth, sheight, angle, NULL);
}

void drawSprite(ALLEGRO_BITMAP *image, float posx, float posy, ALLEGRO_COLOR tint, float centerx, float centery, float angle, float swidth, float sheight) {
	al_draw_tinted_scaled_rotated_bitmap(image, tint, centerx, centery, posx, posy, swidth, sheight, angle, NULL);
}

float getSpriteWidth(ALLEGRO_BITMAP *image) {
	return al_get_bitmap_width(image);
}

float getSpriteHeight(ALLEGRO_BITMAP *image) {
	return al_get_bitmap_height(image);
}

void destroySprite(ALLEGRO_BITMAP * &image) {
	al_destroy_bitmap(image);
	image = nullptr;
}

void destroySprite(std::vector <ALLEGRO_BITMAP*> &tImage) {
	for (size_t i = tImage.size(); i > 0; i--) {
		al_destroy_bitmap(tImage[i - 1]);
		tImage[i - 1] = nullptr;
		tImage.pop_back();
	}
}

void loadFont(ALLEGRO_FONT * &font, std::string font_name, int size) {
	ALLEGRO_PATH * path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(path, "Resources");
	al_append_path_component(path, "Fonts");
	al_change_directory(al_path_cstr(path, '/'));
	al_destroy_path(path);

	font = al_load_font(font_name.c_str(), size, NULL);
}

void drawFont(ALLEGRO_FONT * font, ALLEGRO_COLOR text_color, int x, int y, textType text_type, std::string text) {
	al_draw_text(font, text_color, x, y, text_type, text.c_str());
}

void destroyFont(ALLEGRO_FONT * &font) {
	al_destroy_font(font);
	font = nullptr;
}

void showScreen(ALLEGRO_COLOR back_color) {
	al_flip_display();
	al_clear_to_color(back_color);
}

void showScreen(ALLEGRO_COLOR back_color, int x, int y, int width, int height, int SCREEN_WIDTH, int SCREEN_HEIGHT) {
	al_flip_display();
	al_set_clipping_rectangle(x, y, width, height);
	al_clear_to_color(back_color);
	al_set_clipping_rectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}
