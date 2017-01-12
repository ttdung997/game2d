void intro(GLfloat &x1,GLfloat &y1){
	 glColor4f(0,0,1,0.6);
	 win A;
	 A.nhap(1.0,2.0,2.0,2.0,2.0,1.0,1.0,1.0);
	 A.ve();
	 A.thang(x1,y1);
	 glColor3f(0,0,1);
	drawStrokeText("dung bach khoa",-4,4,0);
	 duongthang d[8];
	 glColor4f(0,0,0,1);
	 d[1].nhap(0.0,1.3,0.9,1.3);
	 d[2].nhap(0.0,1.7,0.9,1.7);
	 d[3].nhap(0.9,0.9,0.9,1.3);
	 d[4].nhap(0.9,1.7,0.9,2.1);
	 d[5].nhap(0.9,2.1,2.1,2.1);
	 d[6].nhap(0.9,0.9,2.1,0.9);
	 d[0].nhap(2.1,0.9,2.1,2.1);
	int i;
 	for(i=0;i<=6;i++){
		d[i].ve();
		d[i].kt(x1,y1);
	}
	
}
