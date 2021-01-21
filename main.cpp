#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

//Variable untuk manipulasi sudut pandang
static float x=0.0f,y=10.75f,z=55.0f;      //Posisi Kamera
static float lx=0.0f,ly=0.0f,lz=-1.0f;   //Vektor sudut pandang


void burung(void) {

	GLfloat xS = 20;
	GLfloat yS = 12;
	GLfloat zS = 50;

	//kepala
	glColor3f(0.88, 0.88, 0.1);
	glPushMatrix();
	glTranslatef(xS, yS -4, zS -1);
	glScalef(3 * 4, 3 * 4, 3 * 4);
	glutSolidSphere(0.5, 20, 30);
	glPopMatrix();

	GLfloat x = -48;
	GLfloat y = 8;
	GLfloat z = 23.5;

	//mata kiri
	glColor3f(0.7, 0.6, 0.4);
	glPushMatrix();
	glRotatef(95, 0, 1, 0);
	glTranslatef(x - 5.4, y + 1, z - 4);
	glScalef(1.5 * 4, 1.5 * 4, 1.5 * 4);
	glutSolidSphere(0.3, 20, 30);
	glPopMatrix();
	
	//bola mata kiri
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(95, 0, 1, 0);
	glTranslatef(x - 5.4, y + 1, z - 2.75);
	glScalef(1.5 * 3, 1.5 * 3, 1.5 * 3);
	glutSolidSphere(0.18, 20, 30);
	glPopMatrix();

	// mata kanan
	glPushMatrix();
	glColor3f(0.7, 0.6, 0.4);
	glRotatef(83, 0, 1, 0);
	glTranslatef(x + 4.9, y + 1, z + 5.8);
	glScalef(1.5 * 4, 1.5 * 4, 1.5 * 4);
	glutSolidSphere(0.3, 20, 30);
	glPopMatrix();

	// bola mata kanan
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(83, 0, 1, 0);
	glTranslatef(x + 4.9, y + 1, z + 6.65);
	glScalef(1.5 * 4, 1.5 * 4, 1.5 * 4);
	glutSolidSphere(0.18, 20, 30);
	glPopMatrix();

	//mulut
	glPushMatrix();
	glTranslatef(xS + 5, yS -7 + 2, zS -1);
	glRotatef(90, -0.5, 1, 0);
	glutSolidCone(1.5, 3, 20, 30);
	glPopMatrix();

    glPushMatrix();
	glTranslatef(xS + 5, yS -7 + 2, zS -1);
	glRotatef(90, 0.5, 1, 0);
	glutSolidCone(1.5, 3, 20, 30);
	glPopMatrix();

	//badan
	glPushMatrix();
	glColor3f(0.88, 0.88, 0.1);
	glTranslatef(xS - 7, yS - 10, zS - 0.3);
	glScalef(5 * 4, 4 * 3, 4 * 4);
	glutSolidSphere(0.5, 20, 30);
	glPopMatrix();

	int sudutSayap = 90;
	//sayap
	for (int i = 0; i < 3; i++) {
		//kanan
		glPushMatrix();
		glTranslatef(xS - 6, yS - 7 - i, zS + 7);
		glRotatef(sudutSayap, 1, 10, 0);
		glRotatef(-15 + (i * 8), 0, 1, 0);
		glRotatef(-8.5, 0, 0, 1);
		glScalef(4 * 4.5 - i, 0.6 * 5, 2.5 * 3 - 1);
		glutSolidSphere(0.5, 20, 30);
		glPopMatrix();
		
		//kiri
		glPushMatrix();
		glTranslatef(xS - 6, yS - 7 - i, zS -9 );
		glRotatef(sudutSayap, 1, 10, 0);
		glRotatef(-15 + (i * 8), 0, 1, 0);
		glRotatef(-8.5, 0, 0, 1);
		glScalef(4 * 4.5 - i, 0.6 * 5, 2.5 * 3 - 1);
		glutSolidSphere(0.5, 20, 30);
		glPopMatrix();
	}

	//ekor
	int sudut = 145;
	for (int i = 0; i < 4; i++) {
		
		glPushMatrix();
		glTranslatef(xS - 12.5 + i, yS - 5 - i, zS);
		glRotatef(sudut, 0, 0, 1);
		glScalef(4 * 6.5, 0.6 * 6, (2.5 * 4) - i);
		glutSolidSphere(0.5, 20, 30);
		glPopMatrix();
		sudut += 10;
	}

	//kaki
	     GLUquadricObj *pObj;
         pObj =gluNewQuadric();
         gluQuadricNormals(pObj, GLU_SMOOTH);
         glColor3ub(92, 51, 23);

         glPushMatrix();
		 glTranslatef(xS - 5, yS - 15, zS +2);
         glRotatef(90,1,-1,0);
         gluCylinder(pObj, 0.3, 0.3, 4, 25, 25);
         glPopMatrix();

         glPushMatrix();
		 glTranslatef(xS - 5, yS - 15, zS -2);
         glRotatef(90,1,-1,0);
         gluCylinder(pObj, 0.3, 0.3, 4, 25, 25);
         glPopMatrix();

//	glPopMatrix();
}

void alas(){
    //Menggambar Tanah
    glColor3f(0, 3, 0);
	glBegin(GL_POLYGON);
           glTexCoord2f(0.0f,0.0f);
           glVertex3f(-2000.0f,0.0f,2000.0f);
           glTexCoord2f(5.0f,0.0f);
           glVertex3f(2000.0f,0.0f,2000.0f);
           glTexCoord2f(5.0f,5.0f);
           glVertex3f(2000.0f,0.0f,-2000.0f);
           glTexCoord2f(0.0f,5.0f);
           glVertex3f(-2000.0f,0.0f,-2000.0f);

    glEnd();
    glPopMatrix();
}

//Untuk menampilkan scene
void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);
	glTranslatef(0,10,0);
	static float i = 0;
	i+=0.1;
	glRotatef(i,0,1,0);
	//glRotatef(i,0,1,1);
	//glTranslatef(0,0,i);
	burung();
	glPopMatrix();

	//Halaman
	glColor3f(0, 2.5, 0);
	glBegin(GL_QUADS);
		glVertex3f(-40.0, 0.1, -40.0);
		glVertex3f(-40.0, 0.1,  40.0);
		glVertex3f( 40.0, 0.1,  40.0);
		glVertex3f( 40.0, 0.1, -40.0);
	glEnd();
    glutSwapBuffers();
}


// Fungsi untuk menyesuaikan perspektif ketika window dirubah ukurannya
void changeSize(int w, int h) {

	// Menghindari pembagian oleh 0.
	if(h == 0)
		h = 1;

    // Rasio antara lebar dengan tinggi layar
	float ratio = 1.0* w / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION); //Matrik diset : Matrik Proyeksi
	glLoadIdentity();            //Meload matrik identitas

	// Set the viewport to be the entire window (titik pusat ruang pandang)
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45,ratio,1,1000); //Parameter perspektif (sudut di sumbu yz, rasio lebar/tinggi,
                                     //near clipping planes, far clipping plane)
	glMatrixMode(GL_MODELVIEW);      //Set matrix ke GL_MODELVIEW
	glLoadIdentity();                //Load identity matrix

    //gluLookAt
    gluLookAt(x     , y    , z,
              x + lx,y + ly,z + lz,
		      0.0f  ,1.0f  ,0.0f);

}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


//Fungsi utama
int main(int argc, char **argv) {
    //argc -> a pointer to the unmodified argc variable from the main function
    //argv -> a pointer to the unmodified argv variable from the main function
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    //Parameter posisi window (x,y)
    glutInitWindowPosition(100,100);

    //Parameter ukuran window (panjang,lebar)
    glutInitWindowSize(640,360);

    //Label
	glutCreateWindow("Gilly Huga Anargya");

	// warna bg
    glClearColor( 0.1, 0.5, 1, 0);
    //Fungsi utama untuk menampilkan objek
    glutDisplayFunc(renderScene);

    //Fungsi yang dijalankan dalam keadaan idle
    glutIdleFunc(renderScene);

    //Fungsi untuk mengatur perspektif.
    //Untuk mempertahankan ukuran objek saat jendela dirubah ukurannya
    glutReshapeFunc(changeSize);

    //Mengaktifkan depth testing
    glEnable(GL_DEPTH_TEST);
    //Mengatur Pencahayaan
    glDepthFunc(GL_LESS);

	//lighting 3d 
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

     //Never ending loop, agar layar tidak langsung tertutup
 	 glutMainLoop();
}
