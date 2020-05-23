#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>


void evento_teclado00(bool continuar, ALLEGRO_EVENT_QUEUE *fila_eventos,
		ALLEGRO_EVENT event, int x1, int y1, int x2, int y2) {
	// Loop principal
	while(continuar) {
		al_wait_for_event(fila_eventos, &event);
		if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				continuar = false;
				std::cout << "A tecla Esc foi pressionada" << std::endl;
				std::cout << "Este Loop será encerrado!" << std::endl;
			}
		}
	}
}

void evento_teclado01(bool continuar, ALLEGRO_EVENT_QUEUE *fila_eventos,
		ALLEGRO_EVENT event, int x1, int y1, int x2, int y2) {
	al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(255, 0, 0), 2);
	// Loop principal
	while(continuar) {
		al_wait_for_event(fila_eventos, &event);
		if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				continuar = false;
				std::cout << "A tecla Esc foi pressionada" << std::endl;
				std::cout << "Este Loop será encerrado!" << std::endl;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_W) {
				std::cout << "A tecla 'W' pressionada foi " << std::endl;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_A) {
				std::cout << "A tecla 'A' pressionada foi " << std::endl;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_S) {
				std::cout << "A tecla 'S' pressionada foi " << std::endl;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_D) {
				std::cout << "A tecla 'D' pressionada foi " << std::endl;
			}
		}
	}
}

void evento_teclado02(bool continuar, ALLEGRO_EVENT_QUEUE *fila_eventos,
		ALLEGRO_EVENT event, ALLEGRO_DISPLAY *tela, int x1, int y1, int x2, int y2) {
	al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(255, 0, 0), 2);
	// Loop principal
	while(continuar) {
		al_wait_for_event(fila_eventos, &event);
		if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				std::cout << "A tecla Esc foi pressionada" << std::endl;
				if(al_show_native_message_box(tela, "Esc", "Sair: ", "Deseja sair?", NULL, ALLEGRO_MESSAGEBOX_YES_NO) == 1)
					{
					continuar = false;
					}
				else {
					continuar = true;
				}
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_W) {
				std::cout << "A tecla 'W' pressionada foi " << std::endl;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_A) {
				std::cout << "A tecla 'A' pressionada foi " << std::endl;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_S) {
				std::cout << "A tecla 'S' pressionada foi " << std::endl;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_D) {
				std::cout << "A tecla 'D' pressionada foi " << std::endl;
			}
		}
	}
}

void evento_teclado03(bool continuar, ALLEGRO_EVENT_QUEUE *fila_eventos,
		ALLEGRO_EVENT event, ALLEGRO_DISPLAY *tela, ALLEGRO_FONT *font, int x1, int y1, int x2, int y2) {
	al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(255, 0, 0), 2);
	// Loop principal
	while(continuar) {
		al_wait_for_event(fila_eventos, &event);
		if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				std::cout << "A tecla Esc foi pressionada" << std::endl;
				if(al_show_native_message_box(tela, "Esc", "Sair: ", "Deseja sair?", NULL, ALLEGRO_MESSAGEBOX_YES_NO) == 1)
					{
					continuar = false;
					}
				else {
					continuar = true;
				}

			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_W) {
				std::cout << "A tecla 'W' pressionada foi " << std::endl;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_A) {
				std::cout << "A tecla 'A' pressionada foi " << std::endl;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_S) {
				std::cout << "A tecla 'S' pressionada foi " << std::endl;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_D) {
				std::cout << "A tecla 'D' pressionada foi " << std::endl;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_text(font, al_map_rgb(255, 0, 0), 500, 300, 0, "LEFT");
				al_flip_display();
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_text(font, al_map_rgb(0, 255, 0), 500, 300, 0, "RIGHT");
				al_flip_display();
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_UP) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_text(font, al_map_rgb(0, 0, 255), 500, 300, 0, "UP");
				al_flip_display();
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_DOWN) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_text(font, al_map_rgb(255, 0, 255), 500, 300, 0, "DOWN");
				al_flip_display();
			}
		}
	}
}

void evento_teclado04(bool continuar, ALLEGRO_EVENT_QUEUE *fila_eventos,
		ALLEGRO_EVENT event, ALLEGRO_DISPLAY *tela, ALLEGRO_FONT *font, int x1, int y1, int x2, int y2) {
	al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(255, 0, 0), 2);
	// Loop principal
	while(continuar) {
		al_wait_for_event(fila_eventos, &event);
		if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				std::cout << "A tecla Esc foi pressionada" << std::endl;
				if(al_show_native_message_box(tela, "Esc", "Sair: ", "Deseja sair?", NULL, ALLEGRO_MESSAGEBOX_YES_NO) == 1)
					{
					continuar = false;
					}
				else {
					continuar = true;
				}

			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_W) {
				std::cout << "A tecla 'W' pressionada foi " << std::endl;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_A) {
				std::cout << "A tecla 'A' pressionada foi " << std::endl;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_S) {
				std::cout << "A tecla 'S' pressionada foi " << std::endl;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_D) {
				std::cout << "A tecla 'D' pressionada foi " << std::endl;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_text(font, al_map_rgb(255, 0, 0), 500, 300, 0, "LEFT");
				x1 -= 10; x2 -= 10;
				al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(255, 0, 0), 2);
				al_flip_display();
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_text(font, al_map_rgb(0, 255, 0), 500, 300, 0, "RIGHT");
				x1 += 10; x2 += 10;
				al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(255, 0, 0), 2);
				al_flip_display();
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_UP) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_text(font, al_map_rgb(0, 0, 255), 500, 300, 0, "UP");
				y1 -= 10; y2 -= 10;
				al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(255, 0, 0), 2);
				al_flip_display();
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_DOWN) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_text(font, al_map_rgb(255, 0, 255), 500, 300, 0, "DOWN");
				y1 += 10; y2 += 10;
				al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(255, 0, 0), 2);
				al_flip_display();
			}
		}
	}
}

void evento_teclado05(bool continuar, ALLEGRO_EVENT_QUEUE *fila_eventos, ALLEGRO_EVENT event,
		ALLEGRO_DISPLAY *tela, ALLEGRO_FONT *font, int x1, int y1, int x2, int y2,
		int speed, ALLEGRO_COLOR cor_fundo, int shape, ALLEGRO_COLOR cor_shape) {

	al_draw_rectangle(x1, y1, x2, y2, cor_shape, 2);
	al_flip_display();
	// Loop principal
	while(continuar) {
		al_wait_for_event(fila_eventos, &event);
		if(event.type == ALLEGRO_EVENT_KEY_DOWN) {

			if(event.keyboard.keycode == ALLEGRO_KEY_W) {
				std::cout << "A tecla 'W' pressionada foi " << std::endl;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_A) {
				std::cout << "A tecla 'A' pressionada foi " << std::endl;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_S) {
				std::cout << "A tecla 'S' pressionada foi " << std::endl;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_D) {
				std::cout << "A tecla 'D' pressionada foi " << std::endl;
			}

			al_clear_to_color(cor_fundo);

			if(event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
				x1 -= speed; x2 -= speed;
				al_draw_text(font, al_map_rgb(255, 0, 0), 500, 300, 0, "LEFT");
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
				x1 += speed; x2 += speed;
				al_draw_text(font, al_map_rgb(0, 255, 0), 500, 300, 0, "RIGHT");
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_UP) {
				y1 -= speed; y2 -= speed;
				al_draw_text(font, al_map_rgb(0, 0, 255), 500, 300, 0, "UP");
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_DOWN) {
				y1 += speed; y2 += speed;
				al_draw_text(font, al_map_rgb(255, 0, 255), 500, 300, 0, "DOWN");
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_3) {
				shape = 3;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_4) {
				shape = 4;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_0) {
				shape = 0;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				std::cout << "A tecla Esc foi pressionada" << std::endl;
				if(al_show_native_message_box(tela, "Esc", "Sair: ", "Deseja sair?", NULL, ALLEGRO_MESSAGEBOX_YES_NO) == 1) {
					continuar = false;
				}
				else {
					continuar = true;
				}
			}
			if(shape == 4) {
				al_draw_rectangle(x1, y1, x2, y2, cor_shape, 2);
			}
			else if(shape == 3) {
				al_draw_triangle(x1, y2, x2, y2, x1 + 15, y1, cor_shape, 2);
			}
			else if(shape == 0) {
				al_draw_circle(x1 + 15, y1 + 15, 15, cor_shape, 2);
			}
			al_flip_display();
		}
	}
}


void evento_teclado06(bool continuar, ALLEGRO_EVENT_QUEUE *fila_eventos, ALLEGRO_EVENT event,
		ALLEGRO_DISPLAY *tela, ALLEGRO_FONT *font, int x1, int y1, int x2, int y2,
		int speed, ALLEGRO_COLOR cor_fundo, int shape, ALLEGRO_COLOR cor_shape, int filled_shape) {

	//al_draw_rectangle(x1, y1, x2, y2, cor_shape, 2);
	//al_flip_display();
	// Loop principal
	while(continuar) {
		ALLEGRO_COLOR filled_shape_color;
		al_wait_for_event(fila_eventos, &event);
		if(event.type == ALLEGRO_EVENT_KEY_DOWN) {

			al_clear_to_color(cor_fundo);

			if(event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
				x1 -= speed; x2 -= speed;
				al_draw_text(font, al_map_rgb(255, 0, 0), 500, 300, 0, "LEFT");
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
				x1 += speed; x2 += speed;
				al_draw_text(font, al_map_rgb(0, 255, 0), 500, 300, 0, "RIGHT");
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_UP) {
				y1 -= speed; y2 -= speed;
				al_draw_text(font, al_map_rgb(0, 0, 255), 500, 300, 0, "UP");
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_DOWN) {
				y1 += speed; y2 += speed;
				al_draw_text(font, al_map_rgb(255, 0, 255), 500, 300, 0, "DOWN");
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_3) {
				shape = 3;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_4) {
				shape = 4;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_0) {
				shape = 0;
			}
			// Reset shape color
			else if(event.keyboard.keycode == ALLEGRO_KEY_N) {
				filled_shape = 100;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_B) {
				filled_shape_color = al_map_rgb(255, 255, 255);
				filled_shape = 10;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_V) {
				filled_shape_color = al_map_rgb(255, 0, 0);
				filled_shape = 11;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_G) {
				filled_shape_color = al_map_rgb(0, 255, 0);
				filled_shape = 12;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				std::cout << "A tecla Esc foi pressionada" << std::endl;
				if(al_show_native_message_box(tela, "Esc", "Sair: ", "Deseja sair?", NULL, ALLEGRO_MESSAGEBOX_YES_NO) == 1) {
					continuar = false;
				}
				else {
					continuar = true;
				}
			}
			if(shape == 4 and filled_shape == 100) {
				al_draw_rectangle(x1, y1, x2, y2, cor_shape, 2);
			}
			else if(shape == 3 and filled_shape == 100) {
				al_draw_triangle(x1, y2, x2, y2, x1 + 15, y1, cor_shape, 2);
			}
			else if(shape == 0 and filled_shape == 100) {
				al_draw_circle(x1 + 15, y1 + 15, 15, cor_shape, 2);
			}
			if(shape == 4 and filled_shape == 10) {
				al_draw_filled_rectangle(x1, y1, x2, y2, filled_shape_color);
			}
			else if(shape == 3 and filled_shape == 10) {
				al_draw_filled_triangle(x1, y2, x2, y2, x1 + 15, y1, filled_shape_color);
			}
			else if(shape == 0 and filled_shape == 10) {
				al_draw_filled_circle(x1 + 15, y1 + 15, 15, filled_shape_color);
			}
			if(shape == 4 and filled_shape == 11) {
				al_draw_filled_rectangle(x1, y1, x2, y2, filled_shape_color);
			}
			else if(shape == 3 and filled_shape == 11) {
				al_draw_filled_triangle(x1, y2, x2, y2, x1 + 15, y1, filled_shape_color);
			}
			else if(shape == 0 and filled_shape == 11) {
				al_draw_filled_circle(x1 + 15, y1 + 15, 15, filled_shape_color);
			}
			if(shape == 4 and filled_shape == 12) {
				al_draw_filled_rectangle(x1, y1, x2, y2, filled_shape_color);
			}
			else if(shape == 3 and filled_shape == 12) {
				al_draw_filled_triangle(x1, y2, x2, y2, x1 + 15, y1, filled_shape_color);
			}
			else if(shape == 0 and filled_shape == 12) {
				al_draw_filled_circle(x1 + 15, y1 + 15, 15, filled_shape_color);
			}
			al_flip_display();
		}
	}
}

void evento_teclado07(ALLEGRO_DISPLAY *tela, ALLEGRO_FONT *font_18, ALLEGRO_FONT *font_14, ALLEGRO_COLOR cor_fundo) {
	al_draw_filled_rectangle(450, 360, 780, 550, al_map_rgb(0, 100, 0));
	al_draw_text(font_18, cor_fundo, 580, 400, 0, "Menu Inicial");
	al_draw_line(540, 420, 710, 420, cor_fundo, 2);
	al_draw_text(font_14, cor_fundo, 560, 430, 0, "(I) Iniciar");
	al_draw_text(font_14, cor_fundo, 560, 450, 0, "(C) Carregar um Jogo");
	al_draw_text(font_14, cor_fundo, 560, 470, 0, "(S) Sair");
	al_flip_display();
	al_rest(5);
}

int main() {
	int tela_largura = 1000;
	int tela_altura = 600;
	bool continuar = true;

	ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
	ALLEGRO_EVENT event;
	ALLEGRO_DISPLAY *tela = NULL;
	// Inicialização da Allegro5
	al_init();
	// Inicialização dos Addons
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	// Geração da tela
	tela = al_create_display(tela_largura, tela_altura);
	// Cria fila de eventos
	fila_eventos = al_create_event_queue();
	// Registrar os tipos de eventos que queremos captar na fila de enventos criada logo acima
	// **Neste caso estamos indicando que qualquer tecla pressionada será capturada na fila de eventos
	al_register_event_source(fila_eventos, al_get_keyboard_event_source());
	// Criar fonte e carrega a fonte na variavel
	ALLEGRO_FONT *font_32 = NULL;
	ALLEGRO_FONT *font_18 = NULL;
	ALLEGRO_FONT *font_14 = NULL;
	// Carrega a fonte na variavel
	font_32 = al_load_font("arial.ttf", 32, 0);
	font_18 = al_load_font("arial.ttf", 18, 0);
	font_14 = al_load_font("arial.ttf", 14, 0);
	// Carrega a fonte na variavel
	font_32 = al_load_font("arial.ttf", 32, 0);
	// Variáveis para desenhar teclado
	int x1 = 20; int y1 = 20; int x2 = 50; int y2 = 50;
	int t_x1 = 20; int t_y1 = 20; int t_x2 = 50; int t_y2 = 20; int t_x3 = 20; int t_y3 = 50;
	int cx = 40; int cy = 40; int r = 20;
	int speed = 10;
	int shape = 4;
	int filled_shape = 100;
	// Define cores
	ALLEGRO_COLOR cor_fundo = al_map_rgb(0, 0, 0);
	// Cor objeto
	ALLEGRO_COLOR cor_shape = al_map_rgb(200, 200, 50);
	// Limpa tela e apresenta cor de fundo
	al_clear_to_color(cor_fundo);
	// Apresenta tela
	al_flip_display();

	//evento_teclado00(continuar, fila_eventos, event, font_32, x1, y1, x2, y2);
	//evento_teclado01(continuar, fila_eventos, event, font_32, x1, y1, x2, y2);
	//evento_teclado02(continuar, fila_eventos, event, tela, font_32, x1, y1, x2, y2);
	//evento_teclado03(continuar, fila_eventos, event, tela, font_32, font_32, x1, y1, x2, y2);
	//evento_teclado04(continuar, fila_eventos, event, tela, font_32, x1, y1, x2, y2);
	//evento_teclado05(continuar, fila_eventos, event, tela, font_32, x1, y1, x2, y2, t_x1, t_y1, t_x2, t_y2, t_x3, t_y3, cx, cy, r);
	//evento_teclado06(continuar, fila_eventos, event, tela, font_32, x1, y1, x2, y2, speed, cor_fundo, shape, cor_shape, filled_shape);
	//evento_teclado07(tela, font_18, font_14, cor_fundo);

	// Destrói os ponteiros criados para evitar o consumo desnecessário de memória
	al_destroy_display(tela);

	return 0;
}
