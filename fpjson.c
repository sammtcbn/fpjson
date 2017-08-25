/*
    fpjson - Formatted Print Json
    written by sammtcbn 2017.8.25
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//#define FPJSON_USE_MALLOC 1
#define MAX_MESSAGE_PRINT_LENGTH 1024
#define FPJSON_INDENTATION "    "
//#define FPJSON_INDENTATION "\t"


char *jsonstr = "{\"MyInformation\":{\"deviceId\":\"%s\",\"hostname\":\"%s\",\"sn\":\"%s\",\"mac\":\"%s\",\"version\":\"0.1.1\",\"type\":\"typeA\",\"productName\":\"Phone\",\"manufacture\":\"Inc.\",\"status\":\"1\",\"familys\":[{\"name\":\"john\",\"age\":20},{\"name\":\"helen\",\"age\":18},{\"name\":\"jack\",\"age\":35}],\"time\":%d}}";


void fpjson (char *str)
{
#ifdef FPJSON_USE_MALLOC
    char *outstr;
#else
    char outstr[MAX_MESSAGE_PRINT_LENGTH];
#endif

    int length=0;
    char newstr[2];
    char *INDENT=FPJSON_INDENTATION;
    int quoted  = 0;
    int escaped = 0;
    int indent  = 0;
    int i=0,j=0;

    newstr[0] = 0x00;
    newstr[1] = 0x00;

    if (str == NULL || strlen(str) == 0)
        return;

    length = strlen (str);

#ifdef FPJSON_USE_MALLOC
    outstr= malloc (MAX_MESSAGE_PRINT_LENGTH);
#endif

    memset (outstr, 0 , MAX_MESSAGE_PRINT_LENGTH);

    for (i = 0 ; i < length ; i++)
    {
        char ch = str[i];
        switch (ch)
        {
            case '{':
            case '[':
                newstr[0]= ch;
                strcat(outstr, newstr);	
                if (!quoted)
                {
                    strcat(outstr, "\n");

                    if (!(str[i+1] == '}' || str[i+1] == ']'))
                    {
                        ++indent;

                        for (j = 0 ; j < indent ; j++)
                        {
                            strcat(outstr, INDENT);
                        }
                    }
                }

                break;

            case '}':
            case ']':
                if (!quoted)
                {
                    if ((i > 0) && (!(str[i-1] == '{' || str[i-1] == '[')))
                    {
                        strcat(outstr, "\n");
                        --indent;

                        for (j = 0 ; j < indent ; j++)
                        {
                            strcat(outstr, INDENT);
                        }
                    }
                    else if ((i > 0) && ((str[i-1] == '[' && ch == ']') || (str[i-1] == '{' && ch == '}')))
                    {
                        for (j = 0 ; j < indent ; j++)
                        {
                            strcat(outstr, INDENT);
                        }
                    }
                }

                newstr[0]=ch;
                strcat(outstr, newstr);
				
                break;

            case '"':
                newstr[0]= ch;
                strcat(outstr, newstr);
                escaped = 1;

                if (i > 0 && str[i-1] == '\\')
                {
                    escaped = !escaped;
                }

                if (!escaped)
                {
                    quoted = !quoted;
                }

                break;

            case ',':
                newstr[0]= ch;
                strcat(outstr, newstr);
                if (!quoted)
                {
                    strcat(outstr, "\n");

                    for (j = 0 ; j < indent ; j++)
                    {
                        strcat(outstr, INDENT);
                    }
                }

                break;

            case ':':
                newstr[0]= ch;
                strcat(outstr, newstr);
                if (!quoted)
                {
                    strcat(outstr, "");
                }

                break;

            default:
                newstr[0]= ch;
                strcat(outstr, newstr);
				
                break;
        }
    }

    fprintf (stderr, "outstr=\n%s\n",outstr);

#ifdef FPJSON_USE_MALLOC
    free (outstr);
#endif
}


int main (void)
{
     fpjson (jsonstr);
     return 0;
}
