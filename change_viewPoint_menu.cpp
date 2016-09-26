///////////////////////////////////////////////////////////////////////////
//								Change viewPoint with menu				//
///////////////////////////////////////////////////////////////////////////


// (1) add CONST :

// (2) add define : 

// (3) add GLOBAL varibles :

// (4) add in init() :

// (5) add methods :

void displayTop()
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glViewport(0,0,WIDTH,HEIGHT); // splits window into subwindows
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glFrustum(-1,1,-1,1,0.7,300);
	gluLookAt(eyex,50,eyez-35,eyex+0.001*dirx,30,eyez-35 +0.001*dirz,0,1,0);
	ShowAll();

	glutSwapBuffers();
}

void smallViewPort(int startX, int StartY, int width, int hight, double eyex, double eyey, double eyez
	, double atx, double aty, double atz, int upx, int upy, int upz)
{
	glViewport(startX, StartY, width, hight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 0.7, 300);
	gluLookAt(eyex, eyey, eyez,
		atx, aty, atz, upx, upy, upz);
	ShowAll();
}

void displayCombined()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// regular view -screen 1
	smallViewPort(0, HEIGHT / 2, WIDTH / 2, HEIGHT / 2, eyex, eyey, eyez,
		eyex + dirx, eyey - 0.5, eyez + dirz, 0, 1, 0);

	// top view - screen 2
	smallViewPort(WIDTH / 2, HEIGHT / 2, WIDTH / 2, HEIGHT /2 , eyex, 50, eyez - 35,
		eyex + 0.001*dirx, 30, eyez - 35 + 0.001*dirz,
		0, 1, 0);
	
	// regular view -screen 3
	smallViewPort(0, 0, WIDTH / 2, HEIGHT / 2, eyex, eyey, eyez,
		eyex + dirx, eyey - 0.5, eyez + dirz, 0, 1, 0);


	// top view - screen 4
	smallViewPort(WIDTH / 2, 0, WIDTH / 2, HEIGHT / 2, eyex, 50, eyez - 35,
		eyex + 0.001*dirx, 30, eyez - 35 + 0.001*dirz,
		0, 1, 0);

	glutSwapBuffers();
}


void menu(int option)
{
	switch(option)
	{
	case 1: // 
		glutDisplayFunc(displayTop);
		break;
	case 2:
		glutDisplayFunc(display);
		break;
	case 3:
		glutDisplayFunc(displayCombined);
		break;
	default:
		break;
	}
}

// (6) add in showall() :

// (7) add in display() :

// (8) add in idle() :

// (9) add in mouse left click :

// (10) add in mouse right click :

// (11) add keyboard functions :

// (12) add keyboard special functions :

// (13) add in main :
// menu
	glutCreateMenu(menu);
	glutAddMenuEntry("Top View",1);
	glutAddMenuEntry("Regular View",2);
	glutAddMenuEntry("Combined View",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);