#include<iostream>
using namespace std;
class duongthang{
 public:
	GLfloat x1,y1,x2,y2;
	duongthang(){
		x1=y1=x2=y2=0;
	}
	void nhap(GLfloat X1,GLfloat Y1,GLfloat X2,GLfloat Y2){
	//nhap tu trai sang phai,duoi len tren
		x1=X1;
		x2=X2;
		y1=Y1;
		y2=Y2;
	}
	void ve(){
		glBegin(GL_LINES);
			glVertex3f(x1,y1,0.0f);
			glVertex3f(x2,y2,0.0f);
		glEnd();
	}
	void kt(GLfloat &a,GLfloat &b){
	   if((x1<a && a<x2) || (y1<b && b<y2)){
		if( ( ((y2-y1)*(a-0.05-x1)-(x2-x1)*(b+0.05-y1))>=0 && ((y2-y1)*(a+0.05-x1)-(x2-x1)*(b-0.05-y1))<=0 ) ||
		    ( ((y2-y1)*(a-0.05-x1)-(x2-x1)*(b+0.05-y1))<=0 && ((y2-y1)*(a+0.05-x1)-(x2-x1)*(b-0.05-y1))>=0 ) ||
		    ( ((y2-y1)*(a+0.05-x1)-(x2-x1)*(b+0.05-y1))>=0 && ((y2-y1)*(a-0.05-x1)-(x2-x1)*(b-0.05-y1))<=0 ) ||
		    ( ((y2-y1)*(a+0.05-x1)-(x2-x1)*(b+0.05-y1))<=0 && ((y2-y1)*(a-0.05-x1)-(x2-x1)*(b-0.05-y1))>=0 ) 
		){
			a=-2.9;b=2.9;
		 }
	  }
	}
};

class hcn{
 public:
	GLfloat x1,y1,x2,y2,x3,y3,x4,y4;
	duongthang At,Bt,Ct,Dt;
	hcn(){
		x1=x2=x3=x4=0;
		y1=y2=y3=y4=0;
		At.x1=At.x2=At.y1=At.y2=0;
		Bt.x1=Bt.x2=Bt.y1=Bt.y2=0;
		Ct.x1=Ct.x2=Ct.y1=Ct.y2=0;
		Dt.x1=Dt.x2=Dt.y1=Dt.y2=0;
	}
	void nhap(GLfloat X1,GLfloat Y1,GLfloat X2,GLfloat Y2,GLfloat X3,GLfloat Y3,GLfloat X4,GLfloat Y4){
		//quy tắc nhập,trái trên,phải trên.phải dưới.trái dưới
		x1=X1;
		x2=X2;
		x3=X3;
		x4=X4;
		y1=Y1;
		y2=Y2;
		y3=Y3;
		y4=Y4;
		At.nhap(X1, Y1, X2, Y2);
		Bt.nhap(X3, Y3, X2, Y2);
		Ct.nhap(X4, Y4, X3, Y3);
		Dt.nhap(X4, Y4, X1, Y1);
	}
	void ve(){
	glBegin(GL_POLYGON);
		glVertex3f(x1,y1,0.0f);
		glVertex3f(x2,y2,0.0f);
		glVertex3f(x3,y3,0.0f);
		glVertex3f(x4,y4,0.0f);
	glEnd();
	}
	void kt(GLfloat &a,GLfloat &b){
		/*if(x1<a-0.05 && a+0.05<x2 && b+0.05<y1 && b-0.05>y3){
			a=b=0;
		}*/
		At.kt(a,b);
		Bt.kt(a,b);
		Ct.kt(a,b);
		Dt.kt(a,b);
	}
};

class win:public hcn{
 public:
	void thang(GLfloat &a,GLfloat &b){
		if(x1<a && a<x2 && b<y1 && b>y3){
			a=-2.9;b=2.9;
			cout<<"ban da chien thang"<<endl;
		}
	}
	
};

class duongtron{
 public:
	GLfloat xc,yc,r;
	duongtron(){
		xc=yc=r=0;
	}
	void nhap(GLfloat X,GLfloat Y,GLfloat R){
		xc=X;
		yc=Y;
		r=R;
	}
	void ve(){
		GLfloat i,j;
		for(i=xc-r;i<=xc+r;i=i+0.01){
		for(j=yc-r;j<=yc+r;j=j+0.01){
			if((i-xc)*(i-xc)+(j-yc)*(j-yc)<=r*r){
				glBegin(GL_POINTS);
					glVertex3f(i,j,0.0f);
				glEnd();
			}
		}
		}
	}
	void kt(GLfloat &a,GLfloat &b){
		if((a-xc)*(a-xc)+(b-yc)*(b-yc)<=r*r){
			a=0;b=0;
		}
	}
};

class move{
 public:	
	hcn A;
	duongtron B;
	void nhaphcn(GLfloat X1,GLfloat Y1,GLfloat X2,GLfloat Y2,GLfloat X3,GLfloat Y3,GLfloat X4,GLfloat Y4){
		A.x1=X1;
		A.x2=X2;
		A.x3=X3;
		A.x4=X4;
		A.y1=Y1;
		A.y2=Y2;
		A.y3=Y3;
		A.y4=Y4;
	}
	void movetx(GLfloat X,GLfloat Y,GLfloat R,GLfloat &tt,GLfloat d,GLfloat c,GLfloat &a,GLfloat &b,int &kt){
		if(kt==0){
			B.nhap(d+X+tt,Y,R);
			B.ve();
			if(B.xc>c+X){
				
				tt=0;
				kt=1;
				}
			}
		 if(kt==1){
			B.nhap(c+X+tt,Y,R);
			B.ve();
			if(B.xc<=d+X){
				
				tt=0;
				kt=0;
				}
			}
			B.kt(a,b);
	}
	void movety(GLfloat X,GLfloat Y,GLfloat R,GLfloat &tt,GLfloat d,GLfloat c,GLfloat &a,GLfloat &b,int &kt){
		if(kt==0){
			B.nhap(X,d+Y+tt,R);
			B.ve();
			if(B.yc>c+Y){
				
				tt=0;
				kt=1;
				}
			}
		 if(kt==1){
			B.nhap(X,c+Y+tt,R);
			B.ve();
			if(B.yc>c+Y){
				
				tt=0;
				kt=0;
				}
			}
			B.kt(a,b);
	}
	
	void movex(GLfloat &tt,GLfloat d,GLfloat c,GLfloat &a,GLfloat &b,int &kt){
		GLfloat x01,x02;
		x01=A.x1;
		x02=A.x2;
		if(kt==0){
			
			A.nhap(d+A.x1+tt,A.y1,d+A.x2+tt,A.y2,d+A.x3+tt,A.y3,d+A.x4+tt,A.y4);
			A.ve();
			
			if(A.x2>=c+x01){
				tt=0;
				kt=1;
				}
			}
		 if(kt==1){
			A.nhap(c+A.x1-A.x2+A.x1+tt,A.y1,c+A.x2-A.x2+A.x1+tt,A.y2,c+A.x3-A.x2+A.x1+tt,A.y3,c+A.x4-A.x2+A.x1+tt,A.y4);
			A.ve();
			if(A.x1<=d+x01){
				tt=0;
				kt=0;
				}
			}
			A.kt(a,b);
	}
	void movey(GLfloat &tt,GLfloat d,GLfloat c,GLfloat &a,GLfloat &b,int &kt){
		GLfloat y01,y02;
		y01=A.y1;
		y02=A.y3;
		if(kt==0){
			
			A.nhap(A.x1,d+A.y1+tt,A.x2,d+A.y2+tt,A.x3,d+A.y3+tt,A.x4,d+A.y3+tt);
			A.ve();
			if(A.y3>=c+y02){
				
				tt=0;
				kt=1;
				}
			}
		 if(kt==1){
			A.nhap(A.x1,c+A.y1+tt,A.x2,c+A.y2+tt,A.x3,c+A.y3+tt,A.x4,c+A.y4+tt);
			A.ve();
			if(A.y1<=d+y01){
				
				tt=0;
				kt=0;
				}
			}
			A.kt(a,b);
	}
	void movexn(GLfloat &tt,GLfloat d,GLfloat c,GLfloat &a,GLfloat &b,int &kt){
		GLfloat x01,x02;
		x01=A.x1;
		x02=A.x2;
		if(kt==1){
			
			A.nhap(d+A.x1-tt,A.y1,d+A.x2-tt,A.y2,d+A.x3-tt,A.y3,d+A.x4-tt,A.y4);
			A.ve();
			
			if(A.x2>=c+x01){
				
				tt=0;
				kt=0;
				}
			}
		 if(kt==0){
			A.nhap(c+A.x1-tt-A.x2+A.x1,A.y1,c+A.x2-tt-A.x2+A.x1,A.y2,c+A.x3-tt-A.x2+A.x1,A.y3,c+A.x4-tt-A.x2+A.x1,A.y4);
			A.ve();
			if(A.x1<=d+x01){
				
				tt=0;
				kt=1;
				}
			}
			A.kt(a,b);
	}
	void moveyn(GLfloat &tt,GLfloat d,GLfloat c,GLfloat &a,GLfloat &b,int &kt){
		GLfloat y01,y02;
		y01=A.y1;
		y02=A.y3;
		if(kt==1){
			
			A.nhap(A.x1,d+A.y1-tt,A.x2,d+A.y2-tt,A.x3,d+A.y3-tt,A.x4,d+A.y3-tt);
			A.ve();
			if(A.y3>=c+y02){
				
				tt=0;
				kt=0;
				}
			}
		 if(kt==0){
			A.nhap(A.x1,c+A.y1-tt,A.x2,c+A.y2-tt,A.x3,c+A.y3-tt,A.x4,c+A.y3-tt);
			A.ve();
			if(A.y1<=d+y01){
				
				tt=0;
				kt=1;
				}
			}
			A.kt(a,b);
	}
};


