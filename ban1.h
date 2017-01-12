void ban1(GLfloat &x1,GLfloat &y1,GLfloat &xtt,GLfloat &ytt,int &kt){
	int i;
	hcn A[3];
	glColor4f(0,0,0,1);
	A[0].nhap(-1,3,-0.5,3,-0.5,1,-1,1);
	A[1].nhap(-3,0.5,-0.5,0.5,-0.5,0,-3,0);
	A[2].nhap(1,1,3,1,3,0.5,1,0.5);
	for(i=0;i<=2;i++){
		A[i].ve();
		A[i].kt(x1,y1);
	}
	
	move X;
	X.nhaphcn(0.7,0.5,1,0.5,1,-1,0.7,-1);
	X.movey(ytt,-2,0,x1,y1,kt);
	move Y;
	Y.nhaphcn(1.7,0.5,2.0,0.5,2.0,-1,1.7,-1);
	Y.moveyn(ytt,-2,0,x1,y1,kt);
	
	glColor4f(0,0,1,0.3);
	 win B;
	 B.nhap(2.5,0.5,3,0.5,3,-3,2.5,-3);
	 B.ve();
	 B.thang(x1,y1);
	
}

