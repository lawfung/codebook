/* no negative number */
inline int rit(){
	int f=0;
	char c;
	do{ c=getchar(); }while(c<'0' || c>'9');
	do{
		f=f*10+c-'0';
		c=getchar();
	}while(c>='0' && c<='9');
	return f;
}

inline void out_pos(int x){
	if (x > 9)
		out_pos(x / 10);
	putchar(x % 10 + '0');
}

/* with negative number */
inline int rit(){
	int f=0,key=1;
	char c;
	do{
		c=getchar();
		if(c=='-') key=-1;
	}while(c<'0' || c>'9');
	do{
		f=f*10+c-'0';
		c=getchar();
	}while(c>='0' && c<='9');
	return f*key;
}

inline void out(int x){
	if (x < 0){
		putchar('-');
		out_pos(-x);
	}
	else
		out_pos(x);
}