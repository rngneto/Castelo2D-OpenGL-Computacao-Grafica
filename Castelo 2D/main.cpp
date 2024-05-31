/*
 * Computacao Grafica
 * Prof. Laurindo de Sousa Britto Neto
 * Codigo tarefa da aula 06 - Castelo 2D em OpenGL
 * Aluno: Raimundo Nonato Gomes Neto
 */

// Bibliotecas utilizadas pelo OpenGL
#ifdef __APPLE__ // MacOS
    #define GL_SILENCE_DEPRECATION
    #include <GLUT/glut.h>
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <math.h>
#else // Windows e Linux
    #include <GL/glut.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
    #include <math.h>
#endif

// Dimensões padrão da janela. Largura e altura
int windowWidth = 1024;
int windowHeight = 768;

//Inicializa alguns parametros do GLUT
void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Define a cor de limpeza como branco
}

//Ajusta a projecao para o redesenho da janela
void reshape(int w, int h) {
    windowWidth = w;
    windowHeight = h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

//Função para desenhar cículos
void drawCircle(float cx, float cy, float r, int num_segments) { //(x,y,raio,segmentos)
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * M_PI * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

//Função para desenhar o Castelo
void drawCastel(){
    
     //Ajusta a escala para tornar o castelo maior/menor
    glScalef(0.7, 0.7, 1.0);
    
    // Translada o castelo para cima
    glTranslatef(0, windowHeight * 0.25, 0);
    
    //Teto da torre esquerda
    glColor3f(1.0, 0.0, 0.0); // Vermelho
    glBegin(GL_TRIANGLES);
    glVertex2f(100, 350);  // vértice inferior esquerdo
    glVertex2f(500, 350);   // vértice inferior direito
    glVertex2f(300, 500);   // vértice superior central
    glEnd();
    
    //Mastro da torre esquerda
	glColor3f(0.0, 0.0, 0.0); // Preto
	glLineWidth(3.0); // Define a largura da linha
	glBegin(GL_LINES);
	glVertex2f(300, 500);   // Início do mastro
	glVertex2f(300, 700);   // Final do mastro
	glEnd();	
	
	//Bandeira da torre esquerda
	glColor3f(0.5, 1.0, 0.0); // Verde limão
	glBegin(GL_QUADS);
	glVertex2f(297, 700);   // Canto superior esquerdo
	glVertex2f(297, 600);   // Canto inferior esquerdo
	glVertex2f(120, 600);   // Canto inferior direito
	glVertex2f(120, 700);   // Canto superior direito
	glEnd();
    
    //Base da torre esquerda
    glColor3f(1.0, 0.5, 0.0); // Laranja
    glBegin(GL_QUADS);
    glVertex2f(200, 350);    // Canto superior esquerdo
    glVertex2f(400, 350);     // Canto superior direito
    glVertex2f(400, 0);       // Canto inferior direito
    glVertex2f(200, 0);      // Canto inferior esquerdo
    glEnd();
    
    //Janela1
    glColor3f(0.0, 1.0, 1.0); // Azul turquesa
    drawCircle(300, 250, 50, 100); //(x,y,raio,segmentos)
    
    //Tijolos da torre esquerda = 3 tijolos amarelos
    glColor3f(1.0, 1.0, 0.0); // Amarelo
  	
    //Primeiro tijolo
	glBegin(GL_QUADS);
	glVertex2f(220, 180);    // Canto superior esquerdo
	glVertex2f(300, 180);    // Canto superior direito
	glVertex2f(300, 150);    // Canto inferior direito
	glVertex2f(220, 150);    // Canto inferior esquerdo
	glEnd();
	
    //Segundo tijolo
	glBegin(GL_QUADS);
	glVertex2f(300, 120);    // Canto superior esquerdo 
	glVertex2f(380, 120);    // Canto superior direito
	glVertex2f(380, 90);    // Canto inferior direito
	glVertex2f(300, 90);    // Canto inferior esquerdo
	glEnd();

	//Terceiro tijolo
	glBegin(GL_QUADS);
	glVertex2f(220, 60);    // Canto superior esquerdo
	glVertex2f(300, 60);    // Canto superior direito
	glVertex2f(300, 30);    // Canto inferior direito
	glVertex2f(220, 30);    // Canto inferior esquerdo
	glEnd();
    
    //Teto da torre central
    glColor3f(1.0, 0.0, 0.0); // Vermelho
    glBegin(GL_TRIANGLES);
    glVertex2f(500, 400);  // vértice inferior esquerdo
    glVertex2f(900, 400);   // vértice inferior direito
    glVertex2f(700, 550);   // vértice superior central
    glEnd();
    
	//Mastro da torre central
	glColor3f(0.0, 0.0, 0.0); // Preto
	glLineWidth(3.0); // Define a largura da linha
	glBegin(GL_LINES);
	glVertex2f(700, 550);   // Início do mastro
	glVertex2f(700, 750);   // Final do mastro
	glEnd();
	
	//Bandeira da torre central
	glColor3f(0.5, 1.0, 0.0); // Verde limão
	glBegin(GL_QUADS);
	glVertex2f(297+400, 750);   // Canto superior esquerdo
	glVertex2f(297+400, 650);   // Canto inferior esquerdo
	glVertex2f(120+400, 650);   // Canto inferior direito
	glVertex2f(120+400, 750);   // Canto superior direito
	glEnd();

    
    //Base da torre central
    glColor3f(1.0, 0.5, 0.0); // Laranja
    glBegin(GL_QUADS);
    glVertex2f(600, 400);    // Canto superior esquerdo
    glVertex2f(800, 400);     // Canto superior direito
    glVertex2f(800, 250);       // Canto inferior direito
    glVertex2f(600, 250);      // Canto inferior esquerdo
    glEnd();
    
    //Janela2
    glColor3f(0.0, 1.0, 1.0); // Azul turquesa
    drawCircle(700, 325, 50, 100); //(x,y,raio,segmentos)
    
    //Teto da torre direita
    glColor3f(1.0, 0.0, 0.0); // Vermelho
    glBegin(GL_TRIANGLES);
    glVertex2f(900, 350);   // vértice inferior esquerdo
    glVertex2f(1300, 350);   // vértice inferior direito
    glVertex2f(1100, 500);  //vértice superior central
    glEnd();
    
    // Mastro da torre direita
	glColor3f(0.0, 0.0, 0.0); // Preto
	glLineWidth(3.0); // Define a largura da linha
	glBegin(GL_LINES);
	glVertex2f(1100, 500);   // Início do mastro
	glVertex2f(1100, 700);   // Final do mastro
	glEnd();
	
	// Bandeira da torre direita
	glColor3f(0.5, 1.0, 0.0); // Verde limão
	glBegin(GL_QUADS);
	glVertex2f(299+981, 700);   // Canto superior esquerdo
	glVertex2f(299+981, 600);   // Canto inferior esquerdo
	glVertex2f(120+981, 600);   // Canto inferior direito
	glVertex2f(120+981, 700);   // Canto superior direito
	glEnd();
    
    //Base da torre direita
    glColor3f(1.0, 0.5, 0.0); // Laranja
    glBegin(GL_QUADS);
    glVertex2f(1000, 350);    // Canto superior esquerdo
    glVertex2f(1200, 350);     // Canto superior direito
    glVertex2f(1200, 0);       // Canto inferior direito
    glVertex2f(1000, 0);      // Canto inferior esquerdo
    glEnd();
    
    //Janela3
    glColor3f(0.0, 1.0, 1.0); // Azul turquesa
    drawCircle(1100, 250, 50, 100); //(x,y,raio,segmentos)
    
    //Tijolos torre direita = 3 tijolos amarelos     
    glColor3f(1.0, 1.0, 0.0); // Amarelo
  	
    //Primeiro tijolo 
	glBegin(GL_QUADS);
	glVertex2f(220 + 875, 180);    // Canto superior esquerdo
	glVertex2f(300 + 875, 180);    // Canto superior direito
	glVertex2f(300 + 875, 150);    // Canto inferior direito
	glVertex2f(220 + 875, 150);    // Canto inferior esquerdo
	glEnd();
	
    //Segundo tijolo
	glBegin(GL_QUADS);
	glVertex2f(300 + 720, 120);    // Canto superior esquerdo (x aumentado para 320)
	glVertex2f(380 + 720, 120);    // Canto superior direito (x aumentado para 400)
	glVertex2f(380 + 720, 90);    // Canto inferior direito
	glVertex2f(300 + 720, 90);    // Canto inferior esquerdo
	glEnd();

	//Terceiro tijolo
	glBegin(GL_QUADS);
	glVertex2f(220 + 875, 60);    // Canto superior esquerdo
	glVertex2f(300 + 875, 60);    // Canto superior direito
	glVertex2f(300 + 875, 30);    // Canto inferior direito
	glVertex2f(220 + 875, 30);    // Canto inferior esquerdo
	glEnd();
    
    //Mureta Amarela
    glColor3f(1.0, 1.0, 0.0); // Amarelo
    glBegin(GL_QUADS);
    
    glVertex2f(1000, 250);    // Canto superior esquerdo
    glVertex2f(400, 250);     // Canto superior direito
    glVertex2f(400, 0);       // Canto inferior direito
    glVertex2f(1000, 0);      // Canto inferior esquerdo
    glEnd();
    
    //Tijolos na mureta   = 4 tijolos laranjas
    glColor3f(1.0, 0.5, 0.0); // Laranja
    
    //Primeiro tijolo
	glBegin(GL_QUADS);
	glVertex2f(220 + 310, 180+40);    // Canto superior esquerdo
	glVertex2f(300 + 310, 180+40);    // Canto superior direito
	glVertex2f(300 + 310, 150+40);    // Canto inferior direito
	glVertex2f(220 + 310, 150+40);    // Canto inferior esquerdo
	glEnd();
	
	//Segundo tijolo
	glBegin(GL_QUADS);
	glVertex2f(220 + 250, 60);    // Canto superior esquerdo
	glVertex2f(300 + 250, 60);    // Canto superior direito
	glVertex2f(300 + 250, 30);    // Canto inferior direito
	glVertex2f(220 + 250, 30);    // Canto inferior esquerdo
	glEnd();

	//Terceiro tijolo
	glBegin(GL_QUADS);
	glVertex2f(220 + 570, 180+40);    // Canto superior esquerdo
	glVertex2f(300 + 570, 180+40);    // Canto superior direito
	glVertex2f(300 + 570, 150+40);    // Canto inferior direito
	glVertex2f(220 + 570, 150+40);    // Canto inferior esquerdo
	glEnd();
	
	//Quarto tijolo
	glBegin(GL_QUADS);
	glVertex2f(220 + 625, 60);    // Canto superior esquerdo
	glVertex2f(300 + 625, 60);    // Canto superior direito
	glVertex2f(300 + 625, 30);    // Canto inferior direito
	glVertex2f(220 + 625, 30);    // Canto inferior esquerdo
	glEnd();
    
    //Porta
    glColor3f(0.0, 0.0, 0.0); // Preto
    glBegin(GL_QUADS);
    glVertex2f(600, 175);    // Canto superior esquerdo
    glVertex2f(800, 175);     // Canto superior direito
    glVertex2f(800, 0);       // Canto inferior direito
    glVertex2f(600, 0);      // Canto inferior esquerdo
    glEnd();
    
    //Batedor
    glColor3f(1.0, 1.0, 0.0); // Circulo externo amarelo
    drawCircle(700, 75, 25, 100); //(x,y,raio,segmentos)    
    glColor3f(0.0, 0.0, 0.0); // Circulo interno preto
    drawCircle(700, 75, 20, 100); //(x,y,raio,segmentos)    
    glColor3f(1.0, 1.0, 0.0); // Circulo amarelo "braço do batedor"
    drawCircle(700, 95, 10, 100); //(x,y,raio,segmentos)    
    
}

//Funcao usada  para desenhar na tela 
void display() {
	
	//Limpa o Buffer de Cores e reinicia a matriz
    glClear(GL_COLOR_BUFFER_BIT);
    drawCastel(); // Chama a função 'drawCastel' para desenhar o castelo
    glutSwapBuffers();
    glFlush(); // manda o OpenGl renderizar as primitivas
}

//Funcao principal
int main(int argc, char** argv) {
	
    glutInit(&argc, argv);// Passagens de parametros C para o glut
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);// Selecao do Modo do Display e do Sistema de cor utilizado
    glutInitWindowSize(windowWidth, windowHeight);// Tamanho da janela do OpenGL
    glutCreateWindow("Castelo 2D - Raimundo Neto");// Da nome para uma janela OpenGL
    init();// Chama a funcao init();
    glutReshapeFunc(reshape);//funcao callback para redesenhar a tela
    glutDisplayFunc(display);//funcao callback de desenho
    glutMainLoop();// executa o loop do OpenGL
    return EXIT_SUCCESS; // retorna 0 para o tipo inteiro da funcao main()
}