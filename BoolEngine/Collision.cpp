#include "Collision.h"


bool collisionBox(ALLEGRO_BITMAP *image, float posx, float posy, ALLEGRO_BITMAP *sec_image, float sec_posx, float sec_posy) {
	bool collision = false;

	if (!(posx + al_get_bitmap_width(image) < sec_posx || posx > sec_posx + al_get_bitmap_width(sec_image) ||  posy + al_get_bitmap_height(image) < sec_posy || posy > sec_posy + al_get_bitmap_height(sec_image))) {
		collision = true;
	}

	return collision;
}

bool collisionDistance(float posx, float posy, float radius, float sec_posx, float sec_posy, float sec_radius) {
	bool collision = false;

	if (sqrt(pow(posx - sec_posx, 2) + pow(posy - sec_posy, 2)) <= (radius + sec_radius)) {
		collision = true;
	}

	return collision;
}

bool collisionPixel(ALLEGRO_BITMAP *image, float posx, float posy, ALLEGRO_BITMAP *sec_image, float sec_posx, float sec_posy) {
	int top, bottom, left, right;

	if ((posx + al_get_bitmap_width(image) < sec_posx || posx > sec_posx + al_get_bitmap_width(sec_image) || posy + al_get_bitmap_height(image) < sec_posy || posy > sec_posy + al_get_bitmap_height(sec_image))) {
		return false;
	}
	else {
		top = max_equal(posy, sec_posy);
		bottom = min_equal(posy + al_get_bitmap_height(image), sec_posy + al_get_bitmap_height(sec_image));
		left = max_equal(posx, sec_posx);
		right = min_equal(posx + al_get_bitmap_width(image), sec_posx + al_get_bitmap_width(sec_image));

		for (int i = top; i < bottom; i++) {
			for (int j = left; j < right; j++) {
				al_lock_bitmap(image, al_get_bitmap_format(image), ALLEGRO_LOCK_READONLY);
				al_lock_bitmap(sec_image, al_get_bitmap_format(sec_image), ALLEGRO_LOCK_READONLY);
				ALLEGRO_COLOR color = al_get_pixel(image, j - posx, i - posy);
				ALLEGRO_COLOR sec_color = al_get_pixel(sec_image, j - sec_posx, i - sec_posy);

				if (color.a != 0 && sec_color.a != 0) {
					return true;
				}
			}
		}
	}
	return false;
}

float max_equal(float x, float y) {
	if (x >= y) return x;
	else return y;
}

float min_equal(float x, float y) {
	if (x <= y) return x;
	else return y;
}
