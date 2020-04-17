#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

// Váriaveis globais
char caixa_titulo[] = "Projeto QUINZE2";

// Função que mostra a caixa de texto
int mostra_caixa_mensagem(ALLEGRO_DISPLAY *display, int tipo, char titulo_caixa[], char titulo_mensagem[], char texto[]) {
	int resposta = al_show_native_message_box(display, titulo_caixa, titulo_mensagem, texto, NULL, tipo);
	return resposta;
}

void caixas_de_mensagens(ALLEGRO_DISPLAY *display) {
	if(mostra_caixa_mensagem(display, ALLEGRO_MESSAGEBOX_YES_NO, caixa_titulo, "PERGUNTA:", "Deseja exibir a mensagem de erro?") == 1) {
		mostra_caixa_mensagem(display, ALLEGRO_MESSAGEBOX_ERROR, caixa_titulo,"Então", "Esta é uma mensagem de erro");
	}
	else {
		mostra_caixa_mensagem(display, ALLEGRO_MESSAGEBOX_WARN, caixa_titulo, "OK, VIDA QUE SEGUE.", "VAMOS VERIFICAR UMA MENSAGEM DE DUVIDA");
	}

	if(mostra_caixa_mensagem(display, ALLEGRO_MESSAGEBOX_QUESTION + ALLEGRO_MESSAGEBOX_YES_NO, caixa_titulo,
			"E esta eh uma mensagem de duvida", "Você deseja continuar?") == 1) {
		mostra_caixa_mensagem( display, ALLEGRO_MESSAGEBOX_WARN, caixa_titulo, "LEGAL...", "Então pressione OK para continuar");
			if(mostra_caixa_mensagem(display, ALLEGRO_MESSAGEBOX_OK_CANCEL, caixa_titulo, "OK ou CANCELA?", "pressione OK para exibir mais uma mensagem ou CANCEL para finalizar") == 1) {
				mostra_caixa_mensagem(display, ALLEGRO_MESSAGEBOX_WARN, caixa_titulo, "PARABÉNS", "Chegamos a ultima mensagem desta sequencia!!");
			}
			else {
				mostra_caixa_mensagem(display, ALLEGRO_MESSAGEBOX_WARN, caixa_titulo, "fim", "SEQUENCIA FINALIZADA PELO USUARIO MAL HUMORADO");
			}
	}
	else {
		mostra_caixa_mensagem(display, ALLEGRO_MESSAGEBOX_WARN, caixa_titulo, "QUE CHATO!", "fim");
	}
}

void mostra_tela(int largura, int altura, ALLEGRO_COLOR cor) {
	// Variáveis locais
	ALLEGRO_DISPLAY *display = NULL;
	// Criar a tela
	display = al_create_display(largura, altura);
	// Definir cor da tela
	al_clear_to_color(cor);
	// Definir o título da tela
	al_set_window_title(display, caixa_titulo);
	// Mostrar a tela no monitor
	al_flip_display();
	// Apresentar a primeira caixa de mensagem
	mostra_caixa_mensagem(display, ALLEGRO_MESSAGEBOX_WARN, caixa_titulo, "TESTES COM CAIXAS DE DALOGO", "Pressione OK para continuar");
	caixas_de_mensagens(display);
	// Aguardar 2 segundos
	al_rest(2.0);
	// Destruir a variável display para liberar memória
	al_destroy_display(display);
}

int main() {
	// Variaveis locais de largura e altura da tela
	int largura_tela = 800;
	int altura_tela = 600;
	// Iniciar a biblioteca Allegro5
	al_init();
	// Variavel local da cor do fundo da tela
	ALLEGRO_COLOR cor_fundo = al_map_rgb(0, 100, 0);
	// Chamar função para mostrar tela
	mostra_tela(largura_tela, altura_tela, cor_fundo);
	return 0;
}
