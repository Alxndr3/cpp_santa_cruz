#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <iostream>

/* *******************************************
 * Tratamento de eventos com o mouse
 * **************************************** */

void eventos_mouse01(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_EVENT event, bool continue_, ALLEGRO_COLOR color_bg) {
	al_clear_to_color(color_bg);
	al_draw_filled_rectangle(100, 100, 130, 130, al_map_rgb(255, 255, 0));
	al_flip_display();

	while(continue_) {
		al_wait_for_event(event_queue, &event);
		if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				if(al_show_native_message_box(display, "Esc", "Sair: ", "Deseja sair?", NULL, ALLEGRO_MESSAGEBOX_YES_NO) == 1) {
					continue_ = false;
				}
				else {
					continue_ = true;
				}
			}
		}
		if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			// Botão direito do Mouse
			if(event.mouse.button == 2) {
				std::cout << "Botão direito do Mouse" << std::endl;
			}
			// Botão direito do Mouse
			else if(event.mouse.button == 1) {
				std::cout << "Botão esquerdo do Mouse" << std::endl;
			}
		}
	}
}

void eventos_mouse02(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_EVENT event, bool continue_, ALLEGRO_COLOR color_bg, int position_x, int position_y) {
	al_draw_filled_rectangle(position_x, position_y, position_x + 10, position_y +10, al_map_rgb(255, 255, 0));
	al_flip_display();

	while(continue_) {
		al_wait_for_event(event_queue, &event);
		if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				if(al_show_native_message_box(display, "Esc", "Sair: ", "Deseja sair?", NULL, ALLEGRO_MESSAGEBOX_YES_NO) == 1) {
					continue_ = false;
				}
				else {
					continue_ = true;
				}
			}
		}
		if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			// Botão direito do Mouse
			if(event.mouse.button == 2) {
				std::cout << "Botão direito do Mouse" << std::endl;
			}
			// Botão direito do Mouse
			else if(event.mouse.button == 1) {
				std::cout << "Botão esquerdo do Mouse" << std::endl;
			}
		}
		if(event.type == ALLEGRO_EVENT_MOUSE_AXES) {
			// Atualiza a variável de posição X do mouse
			position_x = event.mouse.x;
			// Atualiza a variável de posição Y do mouse
			position_y = event.mouse.y;

			al_draw_filled_circle(position_x, position_y, 10, al_map_rgb(0, 255, 255));
		}
		al_flip_display();
	}
}

void eventos_mouse03(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue,
		ALLEGRO_EVENT event, bool continue_, ALLEGRO_COLOR color_bg, ALLEGRO_COLOR color_circle, int position_x, int position_y) {

	al_draw_filled_rectangle(position_x, position_y, position_x + 10, position_y +10, al_map_rgb(255, 255, 0));
	al_flip_display();

	while(continue_) {
		al_wait_for_event(event_queue, &event);
		if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				if(al_show_native_message_box(display, "Esc", "Sair: ", "Deseja sair?", NULL, ALLEGRO_MESSAGEBOX_YES_NO) == 1) {
					continue_ = false;
				}
				else {
					continue_ = true;
				}
			}
		}
		if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			// Botão direito do Mouse
			if(event.mouse.button == 2) {
				std::cout << "Botão direito do Mouse" << std::endl;
				color_circle = al_map_rgb(255, 0, 255);
			}
			// Botão direito do Mouse
			else if(event.mouse.button == 1) {
				std::cout << "Botão esquerdo do Mouse" << std::endl;
				color_circle = al_map_rgb(0, 0, 255);
			}
		}
		if(event.type == ALLEGRO_EVENT_MOUSE_AXES) {
			// Atualiza a variável de posição X do mouse
			position_x = event.mouse.x;
			// Atualiza a variável de posição Y do mouse
			position_y = event.mouse.y;

		}
		al_draw_filled_circle(position_x, position_y, 10, color_circle);
		al_flip_display();
	}
}

void eventos_mouse04(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue,
		ALLEGRO_EVENT event, bool continue_, ALLEGRO_COLOR color_bg, ALLEGRO_COLOR color_circle, int position_x, int position_y) {

	bool button_down;

	al_draw_filled_rectangle(position_x, position_y, position_x + 10, position_y +10, al_map_rgb(255, 255, 0));
	al_flip_display();

	while(continue_) {
		al_wait_for_event(event_queue, &event);
		if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				if(al_show_native_message_box(display, "Esc", "Sair: ", "Deseja sair?", NULL, ALLEGRO_MESSAGEBOX_YES_NO) == 1) {
					continue_ = false;
				}
				else {
					continue_ = true;
				}
			}
		}
		if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if(event.mouse.button & 1) {
				button_down = true;
				color_circle = al_map_rgb(25, 222, 55);
			}
			else if(event.mouse.button & 2) {
				button_down = true;
				color_circle = al_map_rgb(0, 0, 255);
			}
		}
		else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			button_down = false;
		}
		else if(event.type == ALLEGRO_EVENT_MOUSE_AXES) {
			position_x = event.mouse.x;
			position_y = event.mouse.y;
		}
		if(button_down) {
			al_draw_filled_circle(position_x, position_y, 10, color_circle);
			al_flip_display();
		}
	}
}

int main() {
	// Variáveis da tela
	const int screen_width = 1000;
	const int screen_hight = 600;
	int position_x = 100; int position_y = 100;
	bool continue_ = true;
	// Inicialização da biblioteca allegro5 e addons
	al_init();
	al_init_primitives_addon();
	// Detecção teclado
	al_install_keyboard();
	// Detectção mouse
	al_install_mouse();
	// Inicialização da Allegro Display
	ALLEGRO_DISPLAY *display = al_create_display(screen_width, screen_hight);
	// Background coler
	ALLEGRO_COLOR color_bg = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR color_circle;
	// Criar fila de eventos
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	ALLEGRO_EVENT event;

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());

	// eventos_mouse01(display, event_queue, event, continue_, color_bg);
	// eventos_mouse02(display, event_queue, event, continue_, color_bg, position_x, position_y);
	// eventos_mouse03(display, event_queue, event, continue_, color_bg, color_circle, position_x, position_y);
	eventos_mouse04(display, event_queue, event, continue_, color_bg, color_circle, position_x, position_y);

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}
