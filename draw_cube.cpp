///////////////////////////////////////////////////////////////////////////
//								Cube						 			 //
///////////////////////////////////////////////////////////////////////////


// (1) add CONST :

// (2) add define : 

// (3) add GLOBAL varibles :
double offset =0;
// (4) add in init() :

// (5) add methods :
void DrawCube()
{
	// top
	glBegin(GL_POLYGON);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(-1, 1, 1);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(1, 1, 1);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(1, 1, -1);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(-1, 1, -1);
	glEnd();
	// top
	glBegin(GL_POLYGON);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(-1, -1, 1);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(1, -1, 1);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(1, -1, -1);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(-1, -1, -1);
	glEnd();
	// front
	glBegin(GL_POLYGON);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(-1, 1, 1);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(1, 1, 1);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(1, -1, 1);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(-1, -1, 1);
	glEnd();
	// back
	glBegin(GL_POLYGON);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(1, 1, -1);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(1, -1, -1);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(-1, -1, -1);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(-1, 1, -1);
	glEnd();
	// left
	glBegin(GL_POLYGON);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(-1, 1, 1);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(-1, 1, -1);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(-1, -1, -1);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(-1, -1, 1);
	glEnd();
	// right
	glBegin(GL_POLYGON);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(1, 1, 1);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(1, 1, -1);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(1, -1, -1);
	glColor3d(1, 0, 0); // choose color
	glVertex3d(1, -1, 1);
	glEnd();
}
// (6) add in showall() :

	glPushMatrix();
		glRotated(offset * 180 / PI, 0, 1, 0);
		glTranslated(0, 10, 0);
		glScaled(4, 4, 4);
		DrawCube();
	glPopMatrix();
// (7) add in display() :

// (8) add in idle() :
	offset+=0.00 ;   // only if you want it to move

// (9) add in mouse left click :

// (10) add in mouse right click :

// (11) add keyboard functions :

// (12) add keyboard special functions :

// (13) add in main :