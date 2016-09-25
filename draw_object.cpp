///////////////////////////////////////////////////////////////////////////
//								Sphere								 //
///////////////////////////////////////////////////////////////////////////


// (1) add CONST :

// (2) add define : 

// (3) add GLOBAL varibles :
double offset =0;

// (4) add in init() :


// (5) add methods :

void DrawCylinder1(int n, double topr, double bottomr)
{
	double alpha;
	double teta = 2*PI/n; 

	for(alpha=0;alpha<2*PI;alpha+=2*teta)
	{
		glBegin(GL_POLYGON);
				glColor3d(fabs(sin(alpha+PI/2)),(1+cos(alpha+PI/2))/2,0.5*cos(alpha+PI/2));
			glVertex3d(topr*sin(alpha),1,topr*cos(alpha));
			glVertex3d(topr*sin(alpha+teta),1,topr*cos(alpha+teta));
				glColor3d(1-fabs(sin(alpha)),0.8*(1+cos(alpha))/2,0.6*cos(alpha));
			glVertex3d(bottomr*sin(alpha+teta),0,bottomr*cos(alpha+teta));
			glVertex3d(bottomr*sin(alpha),0,bottomr*cos(alpha));
		glEnd();
	}
}

void DrawSphere(int n, int l)
{
	double beta;
	double delta = PI/l;
	int i;

	for(beta = -PI/2,i=0;beta<PI/2;beta+=2*delta,i++)
	{
		glPushMatrix();
		glRotated(i*offset,0,1,0);
		glTranslated(0,sin(beta),0);
		glScaled(1,(sin(beta+delta)-sin(beta)),1);
		DrawCylinder1(n,cos(beta+delta),cos(beta));
		glPopMatrix();
	}
}

// (6) add in showall() :

	glPushMatrix();
		glRotated(offset*180/PI,0,1,0);
		glTranslated(0,25,0);
		glScaled(20,20,20);
		DrawSphere(80,80);
	glPopMatrix();

// (7) add in display() :

// (8) add in idle() :
	offset+=0.00 ;   // only if you want it to move
 
// (9) add in mouse left click :

// (10) add in mouse right click :

// (11) add keyboard functions :

// (12) add keyboard special functions :

// (13) add in main :
