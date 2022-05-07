		scanf("%d",&day);//yyyymmdd从1600年之后 
		int y,m,d,c,w;
		y = day/10000;
		m = day%10000/100;
		d = day%100;
		if(m<3){y--;m+=12;
		}
		c = y/100;
		y %= 100;
		w = (y + y/4 + c/4 - 2*c + (26*(m+1))/10 + d -1)%7;
		if(w<0)	w+=7;
		
int is_run(int year)//平0闰1 
{
	return ((year%4==0 && year%100!=0) || year%400==0);
}
int days[2][13]=
{
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};
int daysOfMonth(int year,int month)//  配合前两段 
{
	return (days[isRun][month]);
}
