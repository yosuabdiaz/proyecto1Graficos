/*
 * Instituto Tecnologico de Costa Rica
 * Escuela de Ingenieria en Computacion
 * Computer Graphics
 *
 * Programa: proyecto1
 * Archivo:  proyecto1.c
 */

#include "proyecto1.h"
#include "malloc.h"

void pixel(int x, int y){
    glPointSize(10); /*Tamaño del pincel*/
    glColor3f(0, 0, 0); /*Color del pincel*/
    glBegin(GL_POINTS); /*Inicia o abre el modo de dibujo*/
    glVertex2d(x, y); /*Para dibujar en el plano y recibe las coordenadas x,y  */
    glEnd(); /*termina el modo de dibujo*/ 
    glutSwapBuffers();/*Para que el pixel se quede pintado y no se borre cuando se refresca el buffer */
}

/* recibe cual boton del mause preciona, estado, el x y el y de donde se preciono.*/
void mouse(int btn, int state, int x, int y){
    glClear(GL_COLOR_BUFFER_BIT); /*limpia el buffer al color que esta en el main */
    pixel(x, y);
}


/* funcion principal */
int main(int argc, char** argv){
    glutInit(&argc, argv); /*INICIAR LA LIBRERIA */ 
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); /*Para configurar el modo de pantalla(intencidad del color, doble buffer). Doble buffer es para ver la imagen, los buffer se intercambian para mostrar el dibujo.*/
    glutInitWindowSize(H_SIZE,V_SIZE); /*Configura el tamaño de la ventana */
    glutInitWindowPosition(100,100); /* configura la posicion inical de la ventana*/ 
    glutCreateWindow("Proyecto1");   /* titulo dela ventana */
    gluOrtho2D(0, H_SIZE, V_SIZE, 0); /* prepara el espacion para dibujar*/
    glutMouseFunc(mouse);
    glClearColor(1, 1, 1, 1); /*modifica el fondo*/    
    glutMainLoop();
    return 0;
}
