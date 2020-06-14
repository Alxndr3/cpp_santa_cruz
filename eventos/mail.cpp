#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>


void acertar_alvo(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue,
		ALLEGRO_EVENT ev, ALLEGRO_COLOR color_rect, bool continue_, int pos_x, int pos_y) {

	al_draw_rectangle(20, 20, 50, 50, color_rect, 2);
	al_flip_display();

	while(continue_) {
		al_wait_for_event(event_queue, &ev);
		if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				continue_ = false;
			}
		}
		if(ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
			pos_x = ev.mouse.x;
			pos_y = ev.mouse.y;
		}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if(ev.mouse.button == 1) {
				std::cout << "O botão esquerdo do mouse foi pressionado." << std::endl;
				std::cout << "Posição X: " << pos_x << std::endl;
				std::cout << "Posição Y: " << pos_y << std::endl;
				if(pos_x >= 20 && pos_x <= 50) {
					if(pos_y >= 20 && pos_y <= 50) {
						std::cout << "Acertou o alvo!" << std::endl;
					}
				}
			}
			else if(ev.mouse.button == 2) {
				std::cout << "O botão direito do mouse foi pressionado." << std::endl;
			}
		}
	}
}

void alvo_em_movimento_(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue,
		ALLEGRO_EVENT ev, ALLEGRO_COLOR color_rect, ALLEGRO_COLOR color_bg,
		bool continue_, int pos_x, int pos_y, int pos_x_alvo, int pos_y_alvo) {

	while(continue_) {
		pos_x_alvo += 1;
		al_clear_to_color(color_bg);
		al_draw_rectangle(pos_x_alvo, pos_y_alvo, pos_x_alvo + 100, pos_y_alvo + 100, color_rect, 2);
		al_flip_display();

		al_wait_for_event(event_queue, &ev);
		if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				continue_ = false;
			}
		}
		if(ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
			pos_x = ev.mouse.x;
			pos_y = ev.mouse.y;
		}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if(ev.mouse.button == 1) {
				std::cout << "O botão esquerdo do mouse foi pressionado." << std::endl;
				std::cout << "Posição X: " << pos_x << std::endl;
				std::cout << "Posição Y: " << pos_y << std::endl;
				if(pos_x >= pos_x_alvo && pos_x <= pos_x_alvo + 100) {
					if(pos_y >= pos_y_alvo && pos_y <= pos_y_alvo + 100) {
						std::cout << "Acertou o alvo!" << std::endl;
					}
				}
			}
			else if(ev.mouse.button == 2) {
				std::cout << "O botão direito do mouse foi pressionado." << std::endl;
			}
		}
	}
}

void alvo_em_movimento(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue,
		ALLEGRO_EVENT ev, ALLEGRO_COLOR color_rect, ALLEGRO_COLOR color_bg, int SCREEN_WIDTH,
		bool continue_, int pos_x, int pos_y, int pos_x_alvo, int pos_y_alvo) {

	while(continue_) {
		pos_x_alvo += 1;
		al_clear_to_color(color_bg);
		al_draw_rectangle(pos_x_alvo, pos_y_alvo, pos_x_alvo + 100, pos_y_alvo + 100, color_rect, 2);
		al_flip_display();
		al_rest(0.002);

		if(pos_x_alvo > SCREEN_WIDTH) {
			pos_x_alvo = -20;
		}

		if(!al_is_event_queue_empty(event_queue)) {

			al_wait_for_event(event_queue, &ev);
			if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
				if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
					continue_ = false;
				}
			}
			if(ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
				pos_x = ev.mouse.x;
				pos_y = ev.mouse.y;
			}
			else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
				if(ev.mouse.button == 1) {
					std::cout << "O botão esquerdo do mouse foi pressionado." << std::endl;
					std::cout << "Posição X: " << pos_x << std::endl;
					std::cout << "Posição Y: " << pos_y << std::endl;
					if(pos_x >= pos_x_alvo && pos_x <= pos_x_alvo + 100) {
						if(pos_y >= pos_y_alvo && pos_y <= pos_y_alvo + 100) {
							std::cout << "Acertou o alvo!" << std::endl;
						}
					}
				}
				else if(ev.mouse.button == 2) {
					std::cout << "O botão direito do mouse foi pressionado." << std::endl;
				}
			}
		}
	}
}

void movimento_controlado(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue,
		ALLEGRO_EVENT ev, ALLEGRO_COLOR color_rect, ALLEGRO_COLOR color_bg, int SCREEN_WIDTH,
		bool continue_, int pos_x, int pos_y, int pos_x_alvo, int pos_y_alvo) {

	bool square_moving = true;

	while(continue_) {
		if(square_moving) {
			pos_x_alvo += 1;
		}
		al_clear_to_color(color_bg);
		al_draw_rectangle(pos_x_alvo, pos_y_alvo, pos_x_alvo + 100, pos_y_alvo + 100, color_rect, 2);
		al_flip_display();
		al_rest(0.002);

		if(pos_x_alvo > SCREEN_WIDTH) {
			pos_x_alvo = -20;
		}

		if(!al_is_event_queue_empty(event_queue)) {

			al_wait_for_event(event_queue, &ev);
			if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
				if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
					continue_ = false;
				}
				if(ev.keyboard.keycode == ALLEGRO_KEY_P) {
					square_moving = false;
				}
				else if(ev.keyboard.keycode == ALLEGRO_KEY_C) {
					square_moving = true;
				}
			}
			if(ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
				pos_x = ev.mouse.x;
				pos_y = ev.mouse.y;
			}
			else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
				if(ev.mouse.button == 1) {
					std::cout << "O botão esquerdo do mouse foi pressionado." << std::endl;
					std::cout << "Posição X: " << pos_x << std::endl;
					std::cout << "Posição Y: " << pos_y << std::endl;
					if(pos_x >= pos_x_alvo && pos_x <= pos_x_alvo + 100) {
						if(pos_y >= pos_y_alvo && pos_y <= pos_y_alvo + 100) {
							std::cout << "Acertou o alvo!" << std::endl;
						}
					}
				}
				else if(ev.mouse.button == 2) {
					std::cout << "O botão direito do mouse foi pressionado." << std::endl;
				}
			}
		}
	}
}

void movimento_controlado2(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue,
		ALLEGRO_EVENT ev, ALLEGRO_COLOR color_rect, ALLEGRO_COLOR color_bg, int SCREEN_WIDTH,
		bool continue_, int pos_x, int pos_y, int pos_x_alvo, int pos_y_alvo) {

	bool square_moving = true;
	int moving_right = 1;

	while(continue_) {
		if(square_moving) {
			if(moving_right == 1) {
				pos_x_alvo += 1;
			}
			else {
				pos_x_alvo -= 1;
			}
		}
		al_clear_to_color(color_bg);
		al_draw_rectangle(pos_x_alvo, pos_y_alvo, pos_x_alvo + 100, pos_y_alvo + 100, color_rect, 2);
		al_flip_display();
		al_rest(0.002);

		if(pos_x_alvo > SCREEN_WIDTH) {
			pos_x_alvo = -20;
		}

		if(!al_is_event_queue_empty(event_queue)) {

			al_wait_for_event(event_queue, &ev);
			if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
				if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
					continue_ = false;
				}
				if(ev.keyboard.keycode == ALLEGRO_KEY_P) {
					square_moving = false;
				}
				else if(ev.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
					square_moving = true;
					moving_right = 1;
				}
				else if(ev.keyboard.keycode == ALLEGRO_KEY_LEFT) {
					square_moving = true;
					moving_right = 0;
				}
			}
			if(ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
				pos_x = ev.mouse.x;
				pos_y = ev.mouse.y;
			}
			else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
				if(ev.mouse.button == 1) {
					std::cout << "O botão esquerdo do mouse foi pressionado." << std::endl;
					std::cout << "Posição X: " << pos_x << std::endl;
					std::cout << "Posição Y: " << pos_y << std::endl;
					if(pos_x >= pos_x_alvo && pos_x <= pos_x_alvo + 100) {
						if(pos_y >= pos_y_alvo && pos_y <= pos_y_alvo + 100) {
							std::cout << "Acertou o alvo!" << std::endl;
						}
					}
				}
				else if(ev.mouse.button == 2) {
					std::cout << "O botão direito do mouse foi pressionado." << std::endl;
				}
			}
		}
	}
}

void movimento_controlado3(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_EVENT ev,
		ALLEGRO_COLOR color_rect, ALLEGRO_COLOR color_bg, int SCREEN_WIDTH, int SCREEN_HIGHT,
		bool continue_, int pos_x, int pos_y, int pos_x_alvo, int pos_y_alvo) {
	// Variáveis para movimentação do quadrado.
	bool square_moving = true;
	int moving_right = 1;
	int moving_up = 1;

	while(continue_) {
		al_clear_to_color(color_bg);
		al_draw_rectangle(pos_x_alvo, pos_y_alvo, pos_x_alvo + 100, pos_y_alvo + 100, color_rect, 2);
		al_flip_display();
		al_rest(0.002);
		// Caso square_moving for avaliada como false o quadrando não se move.
		if(square_moving) {
			// Fazer o quadrado mudar de direção.
			if(moving_right == 1) {
				pos_x_alvo += 1;
			}
			else if(moving_right == 0) {
				pos_x_alvo -= 1;
			}
			else if(moving_up == 1) {
				pos_y_alvo -= 1;
			}
			else if(moving_up == 0) {
				pos_y_alvo += 1;
			}
		}
		// Fazer o quadrado dezaparecer em uma extremidade e reaparecer suavemente na outra.
		if(pos_x_alvo > SCREEN_WIDTH) {
			pos_x_alvo = -20;
		}
		if(pos_x_alvo < -100) {
			pos_x_alvo = SCREEN_WIDTH;
		}
		if(pos_y_alvo > SCREEN_HIGHT) {
			pos_y_alvo = -20;
		}
		if(pos_y_alvo < -100) {
			pos_y_alvo = SCREEN_HIGHT;
		}

		if(!al_is_event_queue_empty(event_queue)) {

			al_wait_for_event(event_queue, &ev);
			if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
				if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
					continue_ = false;
				}
				if(ev.keyboard.keycode == ALLEGRO_KEY_P) {
					square_moving = false;
				}
				else if(ev.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
					square_moving = true;
					moving_right = 1;
					moving_up = 2;
				}
				else if(ev.keyboard.keycode == ALLEGRO_KEY_LEFT) {
					square_moving = true;
					moving_right = 0;
					moving_up = 2;
				}
				else if(ev.keyboard.keycode == ALLEGRO_KEY_UP) {
					square_moving = true;
					moving_up = 1;
					moving_right = 2;
				}
				else if(ev.keyboard.keycode == ALLEGRO_KEY_DOWN) {
					square_moving = true;
					moving_up = 0;
					moving_right = 2;
				}
			}
			if(ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
				pos_x = ev.mouse.x;
				pos_y = ev.mouse.y;
			}
			else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
				if(ev.mouse.button == 1) {
					std::cout << "O botão esquerdo do mouse foi pressionado." << std::endl;
					std::cout << "Posição X: " << pos_x << std::endl;
					std::cout << "Posição Y: " << pos_y << std::endl;
					if(pos_x >= pos_x_alvo && pos_x <= pos_x_alvo + 100) {
						if(pos_y >= pos_y_alvo && pos_y <= pos_y_alvo + 100) {
							std::cout << "Acertou o alvo!" << std::endl;
						}
					}
				}
				else if(ev.mouse.button == 2) {
					std::cout << "O botão direito do mouse foi pressionado." << std::endl;
				}
			}
		}
	}
}

int main() {
	int SCREEN_WIDTH = 800;
	int SCREEN_HIGHT = 400;
	int pos_x = 0;
	int pos_y = 0;
	int pos_x_alvo = 20;
	int pos_y_alvo = 20;
	bool continue_ = true;

	al_init();

	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();

	ALLEGRO_DISPLAY *display = al_create_display(SCREEN_WIDTH, SCREEN_HIGHT);
	ALLEGRO_COLOR color_bg = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR color_rect = al_map_rgb(255, 255, 255);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	ALLEGRO_EVENT ev;

	al_clear_to_color(color_bg);

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());

//	acertar_alvo(display, event_queue, ev, color_rect, continue_, pos_x, pos_y);
//	alvo_em_movimento_(display, event_queue, ev, color_rect, color_bg, continue_, pos_x, pos_y,  pos_x_alvo, pos_y_alvo);
//	alvo_em_movimento(display, event_queue, ev, color_rect, color_bg, SCREEN_WIDTH, continue_, pos_x, pos_y,  pos_x_alvo, pos_y_alvo);
//	movimento_controlado(display, event_queue, ev, color_rect, color_bg, SCREEN_WIDTH, continue_, pos_x, pos_y,  pos_x_alvo, pos_y_alvo);
//	movimento_controlado2(display, event_queue, ev, color_rect, color_bg, SCREEN_WIDTH, continue_, pos_x, pos_y,  pos_x_alvo, pos_y_alvo);
	movimento_controlado3(display, event_queue, ev, color_rect, color_bg, SCREEN_WIDTH, SCREEN_HIGHT, continue_, pos_x, pos_y,  pos_x_alvo, pos_y_alvo);

	al_destroy_display(display);

	return 0; }
