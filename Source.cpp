#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
int r = 100;//jari-jari
int a = 9;//value pengurang jari-jari matahari
int j = 0;
int sisi;
float xF = 527, yF = 500,
    xH = 672, yH = 500,
    xI = 718, yI = 373,
    xJ = 600, yJ = 290,
    xG = 481, yG = 373,
    xA = 600, yA = 700;
float merah = 0.0, hijau = 0.0, biru;
float warnaBiruValueX = 0, x, y;
void init() {
    
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_BLEND);         //Tugas2
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    gluOrtho2D(0.0, 1280, 0.0, 720);
    /*
    glClearColor(1, 1, 1, 0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glPointSize(10.0);
    glLoadIdentity();
    glLineWidth(4.0f);
    gluOrtho2D(0.0, 720.0, 0.0, 480.0);
    */
}

void lingkaran(int sisi, int x, int y) {
    /*if (j == 1) {
        glBegin(GL_POLYGON);
    }*/
    glBegin(GL_POLYGON);
    for (int i = 0; i < sisi; i++) {
        glVertex2f((r * cos(2 * 3.14159265 * i / sisi)) + x, (r * sin(2 * 3.14159265 * i / sisi)) + y);
    }
    glEnd();
}
void polygonSegiLima(float merah, float hijau, float xF, float yF, float xH, float yH, float xI, float yI, float xJ, float yJ, float xG, float yG) {
    glBegin(GL_POLYGON);
    glColor3f(merah, hijau, 1);
    glVertex2f(xF, yF);//F
    glVertex2f(xH, yH);//H
    glVertex2f(xI, yI);//I
    glVertex2f(xJ, yJ);//J
    glVertex2f(xG, yG);//G
    glEnd();
}
void cetakSegiLima() {
    xF = 527, yF = 500,
        xH = 672, yH = 500,
        xI = 718, yI = 373,
        xJ = 600, yJ = 290,
        xG = 481, yG = 373;
    merah = 0, hijau = 0.5;
    for (int i = 0; i < 5; i++) {
        polygonSegiLima(merah, hijau, xF, yF, xH, yH, xI, yI, xJ, yJ, xG, yG);
        xF = xF + 8; yF = yF - 10;
        xH = xH - 8; yH = yH - 10;
        xI = xI - 10; yI = yI + 3;
        yJ = yJ + 10;
        xG = xG + 10; yG = yG + 3;
        merah += 0.2;
        hijau += 0.1;
    }
}
void segitigaKiriAtas(float merah, float hijau,float x, float y) {
    glBegin(GL_TRIANGLES); glColor3f(merah, hijau, 1);
    glVertex2f(x, y); glVertex2f(527, 500); glVertex2f(481, 373);
    glEnd();
}
void cetakSegitigaKiriAtas() {
    x = 300, y = 500, merah = 0, hijau = 0.5;
    for (int i = 0; i < 5; i++) {
        segitigaKiriAtas(merah,hijau,x,y);
        x += 30;
        y -= 10;
        merah += 0.2;
        hijau += 0.1;
    }
}
void segitigaKananAtas(float merah, float hijau,float x, float y ) {
    glBegin(GL_TRIANGLES); glColor3f(merah, hijau, 1);
    glVertex2f(x, y); glVertex2f(672, 500); glVertex2f(718, 373);
    glEnd();
}
void cetakSegitigaKananAtas() {
    x = 900, y = 500, merah = 0, hijau = 0.5;
    for (int j = 0; j < 5; j++) {
        segitigaKananAtas(merah, hijau, x, y);
        x -= 30;
        y -= 10;
        merah += 0.2;
        hijau += 0.1;
    }
}
void segitigaAtas(float merah, float hijau, float x, float y) {
    //segitigaAtas
    
    glBegin(GL_TRIANGLES); glColor3f(merah, hijau, 1);
    glVertex2f(x, y); //A
    glVertex2f(527, 500); //F
    glVertex2f(672, 500); //H
    glEnd();
}
void cetakSegitigaAtas() {
    merah = 0; 
    hijau = 0.5;
    x = 600, y = 700;
    for (int i = 0; i < 5; i++) {
        segitigaAtas(merah,hijau,x,y);
        y -= 30;
        merah += 0.2;
        hijau += 0.1;
    }
}
void segitigaKiriBawah(float merah, float hijau,float x,float y) {
    glBegin(GL_TRIANGLES);
    glColor3f(merah, hijau, 1);
    glVertex2f(600, 290);
    glVertex2f(x, y);
    glVertex2f(481, 373);
    glEnd();
}
void cetakSegitigaKiriBawah() {
    x = 400, y = 150, merah = 0.0, hijau = 0.5;
    for (int j = 0; j < 5; j++) {
        segitigaKiriBawah(merah,hijau,x,y);
        x += 25;
        y += 30;
        merah += 0.2;
        hijau += 0.1;
    }
}
void segitigaKananBawah(float merah, float hijau, float x, float y) {
    glBegin(GL_TRIANGLES);
    glColor3f(merah, hijau, 1);
    glVertex2f(600, 290);
    glVertex2f(x, y);
    glVertex2f(718, 373);
    glEnd();
}
void cetakSegitigaKananBawah() {
    x = 800, y = 150, merah = 0.0, hijau = 0.5;
    for (int j = 0; j < 5; j++) {
        segitigaKananBawah(merah, hijau, x, y);
        x -= 25;
        y += 30;
        merah += 0.2;
        hijau += 0.1;
    }
}
void shadow() {
    
    glBegin(GL_TRIANGLES);
    glColor3f(1, 1, 0.6);
    glVertex2f(600, 290); glColor3f(1 ,1, 1);
    glVertex2f(400, 150);
    glVertex2f(800, 150);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3f(1, 1, 0.6);
    glVertex2f(481, 373); glColor3f(1, 1, 1);
    glVertex2f(300, 500);
    glVertex2f(400, 150);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3f(1, 1, 0.6);
    glVertex2f(527, 500); glColor3f(1, 1, 1);
    glVertex2f(600, 700);
    glVertex2f(300, 500);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1, 1, 0.6);
    glVertex2f(672, 500); glColor3f(1, 1, 1);
    glVertex2f(900, 500);
    glVertex2f(600, 700);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1, 1, 0.6);
    glVertex2f(718, 373); glColor3f(1, 1, 1);
    glVertex2f(800, 150);
    glVertex2f(900, 500);
    glEnd();
}
void objek() {
    glClear(GL_COLOR_BUFFER_BIT);
    cetakSegiLima();
    cetakSegitigaKananAtas();
    cetakSegitigaAtas();
    cetakSegitigaKiriAtas();
    cetakSegitigaKiriBawah();
    cetakSegitigaKananBawah();
    shadow();
    glFlush();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1280, 720);//Tugas2
    glutCreateWindow("Tugas 1 | Grafika Komputer H | EdwinDutaRamadhan_672020272");
    init(); 
    glutDisplayFunc(objek);
    //glutFullScreen();
    glutMainLoop();
}
