///////////////////////////////////////////////////////////////////////////
//								control panel							 //
///////////////////////////////////////////////////////////////////////////


// (1) add CONST :

// (2) add define : 

// (3) add GLOBAL varibles :
// controller position
int y_control_top = HEIGHT - 60, y_control_bottom = HEIGHT - 40, y_control = HEIGHT - 50;
int rotate_control_left = 40, rotate_control_right = 60, rotate_control = 50;
int z_control_left = 40, z_control_right = 60, z_control = 50;

// (4) add in init() :

// (5) add methods :
void leftControlRotate()
{
	glViewport(100, 0, 100, 100);
	glMatrixMode(GL_PROJECTION); // setups the projection matrix
	glLoadIdentity();			 // so that now it will be 2D
	glOrtho(-1, 1, -1, 1, -1, 1);

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4d(0.9, 0.9, 0.4, 0.6);
	// frame
	glBegin(GL_POLYGON);
	glVertex2d(-1, -1);
	glVertex2d(-1, 1);
	glVertex2d(1, 1);
	glVertex2d(1, -1);
	glEnd();
	glColor4d(1, 1, 1, 0.6);
	// slide
	glBegin(GL_POLYGON);
	glVertex2d(-0.9, 0.1);
	glVertex2d(0.9, 0.1);
	glVertex2d(0.9, -0.1);
	glVertex2d(-0.9, -0.1);
	glEnd();
	// control
	glColor4d(0, 0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2d((rotate_control) / 50.0 - 1 - 0.1, -0.2);
	glVertex2d((rotate_control) / 50.0 - 1 + 0.1, -0.2);
	glVertex2d((rotate_control) / 50.0 - 1 + 0.1, 0.2);
	glVertex2d((rotate_control) / 50.0 - 1 - 0.1, 0.2);
	glEnd();

	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_MODELVIEW); // stop previous transformations
	glLoadIdentity();

}
void middleControlY()
{
	glViewport(200, 0, 100, 100);
	glMatrixMode(GL_PROJECTION); // setups the projection matrix
	glLoadIdentity();							// so that now it will be 2D
	glOrtho(-1, 1, -1, 1, -1, 1);

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4d(0.9, 0.9, 0.4, 0.6);
	glBegin(GL_POLYGON);
	glVertex2d(-1, -1);
	glVertex2d(-1, 1);
	glVertex2d(1, 1);
	glVertex2d(1, -1);
	glEnd();
	glColor4d(1, 1, 1, 0.6);
	glBegin(GL_POLYGON);
	glVertex2d(-0.1, -0.9);
	glVertex2d(-0.1, 0.9);
	glVertex2d(0.1, 0.9);
	glVertex2d(0.1, -0.9);
	glEnd();
	// control
	glColor4d(0, 0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2d(-0.2, (HEIGHT - y_control) / 50.0 - 1 - 0.1);
	glVertex2d(-0.2, (HEIGHT - y_control) / 50.0 - 1 + 0.1);
	glVertex2d(0.2, (HEIGHT - y_control) / 50.0 - 1 + 0.1);
	glVertex2d(0.2, (HEIGHT - y_control) / 50.0 - 1 - 0.1);
	glEnd();

	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_MODELVIEW); // stop previous transformations
	glLoadIdentity();

}
void rightControlZ()
{
	glViewport(300, 0, 100, 100);
	glMatrixMode(GL_PROJECTION); // setups the projection matrix
	glLoadIdentity();							// so that now it will be 2D
	glOrtho(-1, 1, -1, 1, -1, 1);

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4d(0.9, 0.9, 0.4, 0.6);
	// frame
	glBegin(GL_POLYGON);
	glVertex2d(-1, -1);
	glVertex2d(-1, 1);
	glVertex2d(1, 1);
	glVertex2d(1, -1);
	glEnd();
	glColor4d(1, 1, 1, 0.6);
	// slide
	glBegin(GL_POLYGON);
	glVertex2d(-0.9, 0.1);
	glVertex2d(0.9, 0.1);
	glVertex2d(0.9, -0.1);
	glVertex2d(-0.9, -0.1);
	glEnd();
	// control
	glColor4d(0, 0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2d((z_control) / 50.0 - 1 - 0.1, -0.2);
	glVertex2d((z_control) / 50.0 - 1 + 0.1, -0.2);
	glVertex2d((z_control) / 50.0 - 1 + 0.1, 0.2);
	glVertex2d((z_control) / 50.0 - 1 - 0.1, 0.2);
	glEnd();

	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_MODELVIEW); // stop previous transformations
	glLoadIdentity();

}

void mouse_motion(int x, int y)
{
	if (x>40 + 200 && x<60 + 200 && y>y_control_top && y<y_control_bottom && y < HEIGHT - 10 && y > HEIGHT - 90)
	{
		y_control = y;
		y_control_top = y_control - 10;
		y_control_bottom = y_control + 10;
	}
	if (y>HEIGHT - 60 && y < HEIGHT - 40 && x >rotate_control_left + 100 && x <rotate_control_right + 100 && x > 100 + 10 && x < 200 - 10)
	{
		rotate_control = x - 100;
		rotate_control_left = rotate_control - 10;
		rotate_control_right = rotate_control + 10;
	}
	if (y>HEIGHT - 60 && y < HEIGHT - 40 && x >z_control_left + 300 && x <z_control_right + 300 && x > 300 + 10 && x < 400 - 10)
	{
		z_control = x - 300;
		z_control_left = z_control - 10;
		z_control_right = z_control + 10;
	}
}

// (6) add in showall() :

// (7) add in display() :

	// control 1
	leftControlRotate();
	// control 2
	middleControlY();
	// control 3
	rightControlZ();

// (8) add in idle() :

// (9) add in mouse left click :

// (10) add in mouse right click :

// (11) add keyboard functions :

// (12) add keyboard special functions :

// (13) add in main :
glutMotionFunc(mouse_motion);