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

void pixel(int x, int y, int r, int g, int b){
    glPointSize(1); /*Tamaño del pincel*/
    glColor3f(r, g, b); /*Color del pincel*/
    glBegin(GL_POINTS); /*Inicia o abre el modo de dibujo*/
    glVertex2d(x, y); /*Para dibujar en el plano y recibe las coordenadas x,y  */
    glEnd(); /*termina el modo de dibujo*/ 
    glutSwapBuffers();/*Para que el pixel se quede pintado y no se borre cuando se refresca el buffer */
}

/* recibe cual boton del mause preciona, estado, el x y el y de donde se preciono.*/
/*void mouse(int btn, int state){
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        Bresenham(10, 170, 10, 350, 1, 0, 0);/* una linea recta Vertical
    }
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        Bresenham(10, 170, 10, 350, 0, 1, 0);/* una linea recta Vertical
    }
    
}*/

/*void keyInput(unsigned char key, int x, int y){
    switch(key){
        case 'p':
            glutMouseFunc(mouse);
            break;
        case 'o':
            glutMouseFunc(mouse);
            break;
        case 'r':
            glClear(GL_COLOR_BUFFER_BIT);  /*limpia el buffer al color que esta en el main 
            break;
    }
}*/
/*Algoritmos para las lineas*/
void Bresenham(int x1, int y1, int x2, int y2){
    GLfloat M, p, x, y, t;
    GLint dx, dy;
    if((x2-x1)== 0)
        M= (y2-y1);
    else
        M= (y2-y1)/(x2-x1);
    /*Para calcular las x*/    
    if (fabs(M)<1){
    /*Este if intercambia los valores de x1 con x2 y y1 con y2 en caso de que el punto de salida sea mayor que el punto de llegada*/
        if(x1>x2){
            /*Intercambia x1 con x2*/
            t= x1;
            x1= x2;
            x2= t;
            /*intercambia y1 con y2*/
            t= y1;
            y1= y2;
            y2= t;
        }
        dx= fabs(x1-x2);
        dy= fabs(y2-y1);
        p= 2*dy-dx;
        x= x1;
        y= y1;

        /*Este while trabaja para cuando el punto de salida es menor que el punto de llegada */
        while(x<=x2){
            pixel(x, y, 1, 1, 1);
            x= x+1;
            if(p>=1){
                if(M<1)
                    y= y+1;
                else
                    y= y-1;
                p= p+2*dy-2*dx;
            }
            else{
                y= y;
                p= p+2*dy;
            }
        } 
    }
    /*Para calcular las y*/
    if (fabs(M)>=1){
    /*Este if intercambia los valores de x1 con x2 y y1 con y2 en caso de que el punto de salida sea mayor que el punto de llegada*/
        if(y1>y2){
            /*Intercambia x1 con x2*/
            t= x1;
            x1= x2;
            x2= t;
            /*intercambia y1 con y2*/
            t= y1;
            y1= y2;
            y2= t;
        }
        dx= fabs(x1-x2);
        dy= fabs(y2-y1);
        p= 2*dx-dy;
        x= x1;
        y= y1;

        /*Este while trabaja para cuando el punto de salida es menor que el punto de llegada */
        while(y<=y2){
            pixel(x, y, 1, 1, 1);
            y= y+1;
            if(p>=1){
                if(M>1)
                    x= x+1;
                else
                    x= x-1;
                p= p+2*dx-2*dy;
            }
            else{
                x= x;
                p= p+2*dx;
            }
        } 
    } 
}


/* funcion principal */
int main(int argc, char** argv){
    glutInit(&argc, argv); /*INICIAR LA LIBRERIA */ 
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); /*Para configurar el modo de pantalla(intencidad del color, doble buffer). Doble buffer es para ver la imagen, los buffer se intercambian para mostrar el dibujo.*/
    glutInitWindowSize(H_SIZE,V_SIZE); /*Configura el tamaño de la ventana */
    glutInitWindowPosition(100,100); /* configura la posicion inical de la ventana*/ 
    glutCreateWindow("Proyecto1");   /* titulo dela ventana */
    gluOrtho2D(0, H_SIZE, 0, V_SIZE); /* prepara el espacion para dibujar*/

    /* salida(x,y)  llegada(x,y) x > y siempre */
    /*Bresenham(10,10,50,10,1,1,1);/* una linea recta Horizontal*/
    /*Bresenham(10,30,50,30);/* una linea recta Horizontal*/
    /*Bresenham(10,50,100,50);/* una linea recta Horizontal*/
    /*Bresenham(10,70,100,70);/* una linea recta Horizontal*/

    /*Bresenham(10,90,50,110);/* una linea recta Pendiente negativa*/
    /*Bresenham(30,90,70,110);/* una linea recta Pendiente negativa*/
    /*Bresenham(50,90,150,140);/* una linea recta Pendiente negativa*/
    /*Bresenham(70,90,170,140);/* una linea recta Pendiente negativa*/

    Bresenham(10,170,170,170);/* una linea recta Horizontal
    /*Bresenham(100,80,200,40);*/
    glClearColor(1, 1, 1, 1); /*modifica el fondo*/    
    glutMainLoop();
    return 0;
}
