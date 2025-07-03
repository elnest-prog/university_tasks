

#include <stdio.h>

 
typedef enum States { Normal, Maybe_comment, Comment, Maybe_end } States;

int main(int argc, char **argv)
{
FILE *fi, *fo;				
States State = Normal;		
int c;						


	if (argc != 3)
	{
		
		return 3;
	}
	fi = fopen(argv[1], "rb");
	if (!fi)
	{
		fprintf(stderr, "Input file \"%s\" open error.\n", argv[1]);
		return 1;
	}
	fo = fopen(argv[2], "wb");
	if (!fo)
	{
		fclose(fi);
		fprintf(stderr, "Output file \"%s\" open error.\n", argv[2]);
		return 2;
	}

	while ((c=fgetc(fi)) != EOF)		
	{
		switch (State)	
		{
			case Normal:		
				if (c == '/')			
					State = Maybe_comment;	
				else if (c != '/')
				{
					State = Normal;
					fputc(c, fo);	
				}	
					
			break;
			
			case Maybe_comment:			
				if (c == '/')
				{
					State = Maybe_comment;
					fputc(c, fo);
				}
				else if (c == '*')
					State = Comment;
				else if (c != '*')
				{
					State = Normal;
					fputc('/', fo);
					fputc(c, fo);
				}
			break;

			case Comment:
				if  (c == '*')
					State = Maybe_end;
			break;

			case Maybe_end:
				if (c == '*')
					State = Maybe_end;
				else if (c == '/')
					State = Normal;	
				else if (c != '*')
					State = Comment;
			break; 
		}
	}
}
