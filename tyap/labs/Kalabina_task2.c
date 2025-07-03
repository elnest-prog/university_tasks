

#include <stdio.h>

 
typedef enum States { Normal, Maybe_comment, Multi_comment, Maybe_end, Single_comment, Char, String, Esc_char, Esc_String } States;

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
                else if (c == '\"')
				{
					State = String;
					fputc('\"', fo);	
				}
                else if (c == '\'')
				{
					State = Char;
					fputc('\'', fo);	
				}
                else
				{
					State = Normal;
					fputc(c, fo);	
				}
                    
					
			break;

            case Esc_String:
                fputc(c, fo);
                State = String;
            break;

            case String:
                if (c == '\"') {
                    State = Normal;
                    fputc('\"', fo);	
                }
                else if (c == '\\')
                {
                    State = Esc_String;
                    fputc(c, fo);
                }
                else
                {
                    fputc(c, fo);
                    State = String;
                }
            break;

            case Char:
                if (c == '\'')
                {
                    State = Normal;
                    fputc(c, fo);
                }
                else if (c == '\\')
                {
                    State = Esc_char;
                    fputc(c, fo);
                }
                else
                {
                    State = Char;
                    fputc(c, fo);
                }
                
            break;

            case Esc_char:
                fputc(c, fo);
                State = Char;
            break;

			
			case Maybe_comment:			
	
			if (c == '*')
					State = Multi_comment;
                else if (c == '/')
					State = Single_comment;

                else if (c == '\'')
				{
					State = Char;
					fputc(c, fo);
				}
                else if (c == '\"')
				{
					State = String;
					fputc(c, fo);
				}
                else
				{
					State = Normal;
					fputc('/', fo);
					fputc(c, fo);
				}
			break;

			case Multi_comment:
				if  (c == '*')
					State = Maybe_end;
                else
                {
                    State = Multi_comment;
                }
			break;

			case Single_comment:
				if  (c == '\n' || c == '\r')
                {
					State = Normal;
                    fputc('\n', fo);
                }
                else
                {
                    State = Single_comment;
                }
			break;

			case Maybe_end:
				if (c == '*')
					State = Maybe_end;
				else if (c == '/')
				{
					State = Normal;	
					fputc(' ', fo);
				}
				else
					State = Multi_comment;
			break; 
		}
	}
}
