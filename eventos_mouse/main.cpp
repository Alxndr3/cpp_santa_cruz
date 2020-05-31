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
	// Desenha um quadrado na tela
	al_draw_filled_rectangle(position_x, position_y, position_x + 10, position_y +10, al_map_rgb(255, 255, 0));
	al_flip_display();

	while(continue_) {
		al_wait_for_event(event_queue, &event);
		// Identifica se uma tecla do teclado foi pressionada
		if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
			// Caso a tecla ESC for pressionada mostra uma janela com as opções para encerrar ou permanecer no jogo.
			if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				if(al_show_native_message_box(display, "Esc", "Sair: ", "Deseja sair?", NULL, ALLEGRO_MESSAGEBOX_YES_NO) == 1) {
					continue_ = false;
				}
				else {
					continue_ = true;
				}
			}
		}
		// Identifica se um botão do mouse foi pressionado.
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
	// Variável para identificar se o botão do mouse esta pressionado ou liberado
	bool button_down;
	// Desenha um quadrado na tela
	al_draw_filled_rectangle(position_x, position_y, position_x + 10, position_y +10, al_map_rgb(255, 255, 0));
	al_flip_display();

	while(continue_) {
		al_wait_for_event(event_queue, &event);
		// Detecta se uma tecla do teclado foi pressionada.
		if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
			// Caso a tecla ESC for pressionada mostra uma janela com as opções para encerrar ou permanecer no jogo.
			if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				if(al_show_native_message_box(display, "Esc", "Sair: ", "Deseja sair?", NULL, ALLEGRO_MESSAGEBOX_YES_NO) == 1) {
					continue_ = false;
				}
				else {
					continue_ = true;
				}
			}
		}
		// Identifica qual botão do mouse foi pressionado, atribui uma cor para ele e define a variável button_down como true
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
		// Identifica quando o botão do mouse é liberado e atribui a variável button_down como false
		else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			button_down = false;
		}
		// Identifica a posição do mouse na tela
		else if(event.type == ALLEGRO_EVENT_MOUSE_AXES) {
			position_x = event.mouse.x;
			position_y = event.mouse.y;
		}
		// Desenha na tela quando um dos botões do mouse estiverem pressionados
		if(button_down) {
			al_draw_filled_circle(position_x, position_y, 10, color_circle);
			al_flip_display();
		}
	}
}

void eventos_mouse05(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_EVENT event, bool continue_, ALLEGRO_COLOR color_bg, int position_x, int position_y) {
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
		al_draw_filled_rectangle(0, 330, 1000, 600, al_map_rgb(0, 100, 0));
		al_draw_filled_rectangle(80, 310, 150, 330, al_map_rgb(150, 0, 0));
		al_draw_circle(300, 310, 20, al_map_rgb(255, 255, 0), 1);
		al_draw_rectangle(290, 300, 310, 320, al_map_rgb(255, 255, 0), 1);
		al_draw_line(280, 310, 290, 310, al_map_rgb(255, 255, 0), 1);
		al_draw_line(310, 310, 320, 310, al_map_rgb(255, 255, 0), 1);
		al_draw_line(300, 290, 300, 300, al_map_rgb(255, 255, 0), 1);
		al_draw_line(300, 320, 300, 330, al_map_rgb(255, 255, 0), 1);
		al_flip_display();
	}
}

void eventos_mouse06(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue,
		ALLEGRO_EVENT event, bool continue_, ALLEGRO_COLOR color_bg, ALLEGRO_COLOR color_circle, int position_x, int position_y) {

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
		// Função que identifica quando o botão do mouse é pressionado
		else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			// Identifica se o botão pressionado foi o direito ou esquerdo
			if(event.mouse.button & 1) {
				std::cout << "O botão direito do mouse foi pressionado" << std::endl;
			}
			else if(event.mouse.button & 2) {
				std::cout << "O botão esquerdo do mouse foi pressionado" << std::endl;
			}
		}
		// Função que identifica quando o botão do mouse é liberado
		else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			std::cout << "Soltou o botão do mouse" << std::endl;
		}
		// Função que identifica quando o cursor do mouse sai da tela
		else if(event.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
			std::cout << "Mouse no display" << std::endl;
		}
		// Função que identifica quando o cursor do mouse entra da tela
		else if(event.type == ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY) {
			std::cout << "Mouse fora do display" << std::endl;
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
	//eventos_mouse04(display, event_queue, event, continue_, color_bg, color_circle, position_x, position_y);
	//eventos_mouse05(display, event_queue, event, continue_, color_bg, position_x, position_y);
	eventos_mouse06(display, event_queue, event, continue_, color_bg, color_circle, position_x, position_y);

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}
