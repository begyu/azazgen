#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char azaz[80] = "";
static char azek[80] = "";

int n2s(int x)
{
        int i, kod, len;
        char buf[20];
        char szam[12];

        azaz[0] = '\0';
        if (x == 0)
        {
          strcat(azaz, "nulla");
          return 1;
        }
        sprintf(buf, "%d", x);
        len = strlen(buf);
        for (i=0; i<len; i++)
            szam[len-i-1] = buf[i];
        szam[len] = '\0';

        i = len-1;

        while (1)
        {
                if (szam[i] > '9')
                        return 0; //NULL

                switch (i+1)
                {
                case 2:
                case 5:
                case 8:
                case 11:
                        kod = 3;
                        break;
                case 3:
                case 6:
                case 9:
                case 12:
                        kod = 2;
                        break;
                case 4:
                        kod = 1;
                        break;
                default:
                        kod = 4;
                        break;
                }

                switch (kod)
                {
                case 1:
                        switch (szam[i])
                        {
                        case '0':
                                strcat(azaz, "ezer");
                                break;
                        case '1':
                                strcat(azaz, "egyezer");
                                break;
                        case '2':
                                strcat(azaz, "k‚tezer");
                                break;
                        case '3':
                                strcat(azaz, "h romezer");
                                break;
                        case '4':
                                strcat(azaz, "n‚gyezer");
                                break;
                        case '5':
                                strcat(azaz, "”tezer");
                                break;
                        case '6':
                                strcat(azaz, "hatezer");
                                break;
                        case '7':
                                strcat(azaz, "h‚tezer");
                                break;
                        case '8':
                                strcat(azaz, "nyolcezer");
                                break;
                        case '9':
                                strcat(azaz, "kilencezer");
                                break;
                        default:
                                //return NULL;
                                break;
                        }
                        break;
                case 2:
                        if (((i == 2) && (x > 2000))
                        || ((i > 2) && (szam[i+1] > '0')))
                                strcat(azaz, "-");
                        switch (szam[i])
                        {
                        case '0':
                                break;
                        case '1':
                                strcat(azaz, "egysz z");
                                break;
                        case '2':
                                strcat(azaz, "k‚tsz z");
                                break;
                        case '3':
                                strcat(azaz, "h romsz z");
                                break;
                        case '4':
                                strcat(azaz, "n‚gysz z");
                                break;
                        case '5':
                                strcat(azaz, "”tsz z");
                                break;
                        case '6':
                                strcat(azaz, "hatsz z");
                                break;
                        case '7':
                                strcat(azaz, "h‚tsz z");
                                break;
                        case '8':
                                strcat(azaz, "nyolcsz z");
                                break;
                        case '9':
                                strcat(azaz, "kilencsz z");
                                break;
                        default:
                                //return NULL;
                                break;
                        }
                        break;
                case 3:
                        switch (szam[i])
                        {
                        case '0':
                                break;
                        case '1':
                                if (szam[i-1] != '0')
                                        strcat(azaz, "tizen");
                                else
                                        strcat(azaz, "tˇz");
                                break;
                        case '2':
                                if (szam[i-1] != '0')
                                        strcat(azaz, "huszon");
                                else
                                        strcat(azaz, "hŁsz");
                                break;
                        case '3':
                                strcat(azaz, "harminc");
                                break;
                        case '4':
                                strcat(azaz, "negyven");
                                break;
                        case '5':
                                strcat(azaz, "”tven");
                                break;
                        case '6':
                                strcat(azaz, "hatvan");
                                break;
                        case '7':
                                strcat(azaz, "hetven");
                                break;
                        case '8':
                                strcat(azaz, "nyolcvan");
                                break;
                        case '9':
                                strcat(azaz, "kilencven");
                                break;
                        default:
                                //return NULL;
                                break;
                        }
                        break;
                case 4:
                        switch (szam[i])
                        {
                        case '0':
                                break;
                        case '1':
                                strcat(azaz, "egy");
                                break;
                        case '2':
                                strcat(azaz, "kett‹");
                                break;
                        case '3':
                                strcat(azaz, "h rom");
                                break;
                        case '4':
                                strcat(azaz, "n‚gy");
                                break;
                        case '5':
                                strcat(azaz, "”t");
                                break;
                        case '6':
                                strcat(azaz, "hat");
                                break;
                        case '7':
                                strcat(azaz, "h‚t");
                                break;
                        case '8':
                                strcat(azaz, "nyolc");
                                break;
                        case '9':
                                strcat(azaz, "kilenc");
                                break;
                        default:
                                //return NULL;
                                break;
                        }
                        break;
                default:
                        break;

                }

                if (i == 6)
                        strcat(azaz, "milli˘");
                else if (i == 9)
                        strcat(azaz, "milli rd");

                len = strlen(azaz)-1;
                if (i == 0 && azaz[len] == '-')
                        azaz[len] = '\0';

                i--;
                if (i < 0) break;
        }
        for (i=0; azaz[i]; i++)
        {
                switch (azaz[i])
                {
                case ' ':
                    azek[i] = 'á';
                    break;
                case '‚':
                    azek[i] = 'é';
                    break;
                case 'ˇ':
                    azek[i] = 'í';
                    break;
                case '˘':
                    azek[i] = 'ó';
                    break;
                case '”':
                    azek[i] = 'ö';
                    break;
                case '‹':
                    azek[i] = 'ő';
                    break;
                case 'Ł':
                    azek[i] = 'ú';
                    break;
                default:
                    azek[i] = azaz[i];
                    break;
                }
        }
        azek[i] = '\0';
        return 1; /*not NULL*/
}

int main()
{
  int i;
  FILE *f;

  f = fopen("azaz.txt", "w");
  for (i=0; i<1200000; i++) {n2s(i); fprintf(f, "%d\t%s\n", i, azaz);}
  fclose(f);
  return 0;
}
