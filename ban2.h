void ban2(GLfloat &x1,GLfloat &y1,
          GLfloat &xtt0,GLfloat &xtt1,GLfloat &xtt2,GLfloat &xtt3,GLfloat &xtt4,
	  GLfloat &xtt5,GLfloat &xtt6,GLfloat &xtt7,GLfloat &xtt8,GLfloat &xtt9,
	  int &kt0      ,int &kt1      ,int &kt2      ,int &kt3     ,int &kt4      ,
	  int &kt5      ,int &kt6      ,int &kt7      ,int &kt8      ,int &kt9      ){
	
	glColor4f(0,0,0,1);
	duongthang d[2];
	d[0].nhap(-1,-2,-1,3);
	d[1].nhap(1,-3,1,2);
	d[0].ve();
	d[0].kt(x1,y1);
	d[1].ve();
	d[1].kt(x1,y1);
	move X[10];
	int i;
	for(i=0;i<=4;i++){
		X[i].nhaphcn(-3,2.5-0.9*i,-2.5+0.3*i,2.5-0.9*i,-2.5+0.3*i,2.2-0.9*i,-3,2.2-0.9*i);	
	}
	
		X[0].movexn(xtt0,0,2,x1,y1,kt0);
		X[1].movexn(xtt1,0,2,x1,y1,kt1);	
		X[2].movexn(xtt2,0,2,x1,y1,kt2);	
		X[3].movexn(xtt3,0,2,x1,y1,kt3);	
		X[4].movexn(xtt4,0,2,x1,y1,kt4);
	for(i=6;i<=9;i++){
		X[i].nhaphcn(-1,-2.2+0.9*(i-5),-0.5+0.3*(i-5),-2.2+0.9*(i-5),-0.5+0.3*(i-5),-2.5+0.9*(i-5),-1,-2.5+0.9*(i-5));
	}	
		X[6].movexn(xtt6,0,2,x1,y1,kt6);	
		X[7].movexn(xtt7,0,2,x1,y1,kt7);	
		X[8].movexn(xtt8,0,2,x1,y1,kt8);	
		X[9].movexn(xtt9,0,2,x1,y1,kt9);	
	glColor4f(0,0,1,1);
	 win B;
	 B.nhap(1,0,3,0,3,-3,1,-3);
	 B.ve();
	 B.thang(x1,y1);
}
