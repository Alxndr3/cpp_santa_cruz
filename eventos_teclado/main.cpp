#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>


void draw_rectangle(int x1, int y1, int x2, int y2) {
	ALLEGRO_COLOR cor_quadrado = al_map_rgb(0, 255, 0);
	// Desenha retângulo
	al_draw_rectangle(x1, y1, x2, y2, cor_quadrado, 2);
	al_flip_display();
}

void draw_triagle(int t_x1, int t_y1, int t_x2, int t_y2, int t_x3, int t_y3) {
	ALLEGRO_COLOR cor_triangulo = al_map_rgb(255, 255, 0);
	al_draw_triangle(t_x1, t_y1, t_x2, t_y2, t_x3, t_y3, cor_triangulo, 2);
	al_flip_display();

}

void draw_circle(int cx, int cy, int r) {
	ALLEGRO_COLOR cor_circulo = al_map_rgb(255, 0, 255);
	al_draw_circle(cx, cy, r, cor_circulo, 2);
}

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
	draw_rectangle(x1, y1, x2, y2);
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
	draw_rectangle(x1, y1, x2, y2);
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
	draw_rectangle(x1, y1, x2, y2);
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
	draw_rectangle(x1, y1, x2, y2);
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
				draw_rectangle(x1, y1, x2, y2);
				al_flip_display();
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_text(font, al_map_rgb(0, 255, 0), 500, 300, 0, "RIGHT");
				x1 += 10; x2 += 10;
				draw_rectangle(x1, y1, x2, y2);
				al_flip_display();
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_UP) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_text(font, al_map_rgb(0, 0, 255), 500, 300, 0, "UP");
				y1 -= 10; y2 -= 10;
				draw_rectangle(x1, y1, x2, y2);
				al_flip_display();
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_DOWN) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_text(font, al_map_rgb(255, 0, 255), 500, 300, 0, "DOWN");
				y1 += 10; y2 += 10;
				draw_rectangle(x1, y1, x2, y2);
				al_flip_display();
			}
		}
	}
}


void evento_teclado05(bool continuar, ALLEGRO_EVENT_QUEUE *fila_eventos,
		ALLEGRO_EVENT event, ALLEGRO_DISPLAY *tela, ALLEGRO_FONT *font,
		int x1, int y1, int x2, int y2, int t_x1, int t_y1, int t_x2, int t_y2, int t_x3, int t_y3, int cx, int cy, int r) {
	draw_rectangle(x1, y1, x2, y2);
	al_flip_display();
	// Loop principal
	while(continuar) {
		al_wait_for_event(fila_eventos, &event);
		if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				std::cout << "A tecla Esc foi pressionada" << std::endl;
				if(al_show_native_message_box(tela, "Esc", "Sair: ", "Deseja sair?", NULL, ALLEGRO_MESSAGEBOX_YES_NO) == 1) {
					continuar = false;
				}
				else {
					continuar = true;
				}
			}
			if(event.keyboard.keycode == ALLEGRO_KEY_3) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				draw_triagle(t_x1, t_y1, t_x2, t_y2, t_x3, t_y3);
				al_flip_display();
			}
			if(event.keyboard.keycode == ALLEGRO_KEY_0) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				draw_circle(cx, cy, r);
				al_flip_display();
			}
			if(event.keyboard.keycode == ALLEGRO_KEY_4) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				draw_rectangle(x1, y1, x2, y2);
				al_flip_display();
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
				t_x1 -= 10; t_x2 -= 10; t_x3 -= 10;
				x1 -= 10; x2 -= 10;
				cx -= 10;
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_text(font, al_map_rgb(255, 0, 0), 500, 300, 0, "LEFT");
				draw_rectangle(x1, y1, x2, y2);
				al_flip_display();
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
				t_x1 += 10; t_x2 += 10; t_x3 += 10;
				x1 += 10; x2 += 10;
				cx += 10;
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_text(font, al_map_rgb(0, 255, 0), 500, 300, 0, "RIGHT");
				draw_rectangle(x1, y1, x2, y2);
				al_flip_display();
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_UP) {
				t_y1 -= 10; t_y2 -= 10; t_y3 -= 10;
				y1 -= 10; y2 -= 10;
				cy -= 10;
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_text(font, al_map_rgb(0, 0, 255), 500, 300, 0, "UP");
				draw_rectangle(x1, y1, x2, y2);
				al_flip_display();
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_DOWN) {
				t_y1 += 10; t_y2 += 10; t_y3 += 10;
				y1 += 10; y2 += 10;
				cy += 10;
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_text(font, al_map_rgb(255, 0, 255), 500, 300, 0, "DOWN");
				draw_rectangle(x1, y1, x2, y2);
				al_flip_display();
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
	// Carrega a fonte na variavel
	font_32 = al_load_font("arial.ttf", 32, 0);
	// Variáveis para desenhar teclado
	int x1 = 20; int y1 = 20; int x2 = 50; int y2 = 50;
	int t_x1 = 20; int t_y1 = 20; int t_x2 = 50; int t_y2 = 20; int t_x3 = 20; int t_y3 = 50;
	int cx = 40; int cy = 40; int r = 20;
	// Define cores
	ALLEGRO_COLOR cor_fundo = al_map_rgb(0, 0, 0);
	// Limpa tela e apresenta cor de fundo
	al_clear_to_color(cor_fundo);
	// Apresenta tela
	al_flip_display();

	//evento_teclado00(continuar, fila_eventos, event, font_32, x1, y1, x2, y2);
	//evento_teclado01(continuar, fila_eventos, event, font_32, x1, y1, x2, y2);
	//evento_teclado02(continuar, fila_eventos, event, tela, font_32, x1, y1, x2, y2);
	//evento_teclado03(continuar, fila_eventos, event, tela, font_32, font_32, x1, y1, x2, y2);
	//evento_teclado04(continuar, fila_eventos, event, tela, font_32, x1, y1, x2, y2);
	evento_teclado05(continuar, fila_eventos, event, tela, font_32,
			x1, y1, x2, y2, t_x1, t_y1, t_x2, t_y2, t_x3, t_y3, cx, cy, r);

	// Destrói os ponteiros criados para evitar o consumo desnecessário de memória
	al_destroy_display(tela);

	return 0;
}
