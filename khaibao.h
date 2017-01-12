void drawStrokeText(char*string,int x,int y,int z)
{
          char *c;
          glPushMatrix(); 
          glTranslatef(x, y,z);
          glScalef(0.003f,0.003f,z);

          for (c=string; *c != '\0'; c++)
          {
                glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
          }
          glPopMatrix();
}

void drawBitmapText(char *string,float x,float y,float z) 
{  
	char *c;
	glRasterPos3f(x, y,z);
	for (c=string; *c != '\0'; c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
	}
}


void reshape (int w, int h)
{
   
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode (GL_MODELVIEW);
     
}

void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}
void matphang(void)
{
	
	
	glColor4f(255,255,255,1);
	glBegin(GL_QUADS);
		glVertex3f(-3.0f,3.0f,0.0f);
		glVertex3f(-3.0f,-3.0f,0.0f);
		glVertex3f(3.0f,-3.0f,0.0f);
		glVertex3f(3.0f,3.0f,0.0f);	
	glEnd();
	glColor4f(150, 0, 255,1);
	float i,k;
	int j;
	for(j=1;j<=60;j++){
		if(j%2==0){
		 k=3-0.1*(j-1);
		   for(i=-3.0;i<=3;i=i+0.2){
			
			glBegin(GL_QUADS);
				glVertex3f(i,k,0.0f);
				glVertex3f(i,k-0.1,0.0f);
				glVertex3f(i+0.1,k-0.1,0.0f);
				glVertex3f(i+0.1,k,0.0f);	
			glEnd();
		    }
		}else{
		  k=3-0.1*(j-1);
		    for(i=-2.9;i<=3;i=i+0.2){
			glBegin(GL_QUADS);
				glVertex3f(i,k,0.0f);
				glVertex3f(i,k-0.1,0.0f);
				glVertex3f(i+0.1,k-0.1,0.0f);
				glVertex3f(i+0.1,k,0.0f);	
			glEnd();
		    }
		}	
	}
}
void khoitao(void){
	 glClear (GL_COLOR_BUFFER_BIT);
   glEnable(GL_DEPTH_TEST); // bật chức năng cho phép loại bỏ một phần của đối tượng bị che bởi đối tượng khác
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glEnable(GL_BLEND);
   glLoadIdentity ();    
}
