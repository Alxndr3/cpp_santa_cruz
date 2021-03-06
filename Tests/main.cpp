#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


/*  Programa para a criação de uma tela simples.*/

int main()
{
    //variaveis do jogo
    const int Largura_t = 1080;
    const int Altura_t = 800;
    char Autor [30] = "Jorge do Nascimento Junior";
    int Projeto = 4;
    char Assunto[50] = "Fontes e Textos";


    ALLEGRO_DISPLAY *Tela;   //define um ponteiro para a tela do jogo
    al_init();              //inicializa a biblioteca Allegro 5

    //cria as variaveis com cores
    ALLEGRO_COLOR Azul =        al_map_rgb(0, 0, 255);
    ALLEGRO_COLOR Cor_fundo =   al_map_rgb(0, 100, 0);
    ALLEGRO_COLOR Vermelho =    al_map_rgb(255, 0, 0);
    ALLEGRO_COLOR Preto =       al_map_rgb(0, 0, 0);


    Tela = al_create_display(Largura_t, Altura_t);//cria a tela e define seu tamanho
    al_clear_to_color(Cor_fundo);   //define a cor de fundo para a tela

    //inicialização de AddOns
    al_init_font_addon();
    al_init_ttf_addon();

    //criando variaveis das fontes
    ALLEGRO_FONT *size_16;
    ALLEGRO_FONT *size_32;
    ALLEGRO_FONT *size_56;

    //carrega as fontes
    size_16= al_load_font("orange_juice_2.0.ttf", 16, 0);
    size_32= al_load_font("orange_juice_2.0.ttf", 32, 0);
    size_56= al_load_font("orange_juice_2.0.ttf", 56, 0);

    //Escreveremos na tela
        //primeira frase
        al_draw_text(size_32, Azul, 150, 50, 0, "Ola Pessoal!");
        //apresenta na tela
        al_flip_display();
        //aguarda 1 segundo
        al_rest(1.0);
        //escreve a segunda frase
        al_draw_text(size_32, Vermelho, 150, 100, 0, "Tudo bem com voces?");
        //atualiza a tela
        al_flip_display();
        //aguarde um segundo
        al_rest(1.0);

    //AL_DRAW_TEXTF()
        //Escreve a terceira frase, com variavel inteira
        al_draw_textf(size_16, Azul, 420, 150, ALLEGRO_ALIGN_RIGHT, "este  eh  o  %d  projeto" , Projeto);
        //atualiza a tela
        al_flip_display();
        //aguarde 1 segundo
        al_rest(1.0);
        //Escreve a quarta frase, com variavel texto
        al_draw_textf(size_16, Vermelho, 150, 200, ALLEGRO_ALIGN_LEFT, "Meu nome eh %s" , Autor);
        //Atualiza a tela
        al_flip_display();
        //aguarde 1 segundo
        al_rest(1.0);
        //escreve a quinta frase, com variavel texto
        al_draw_textf(size_56, Preto, 500, 300, ALLEGRO_ALIGN_CENTRE, "%s", Assunto);
        //Atualiza a tela
        al_flip_display();
        //aguarde 3 segundos
        al_rest(3.0);

    //destroi o ponteiro referente a tela
    al_destroy_display(Tela);
   //destroi as fontes
   al_destroy_font(size_16);
   al_destroy_font(size_32);
   al_destroy_font(size_56);
}
