#include <bits/stdc++.h>

int main()
{
    char *program = 0, *modified_program = 0;
    int file_length = 0, i = 0, j = 0;
    bool s_cmt = false;
    bool m_cmt = false;

    FILE *fp = fopen("/home/ikramul/Desktop/201-15-14091/input.txt", "r");
    FILE *fp1 = fopen("/home/ikramul/Desktop/201-15-14091/output.txt","w+");
    FILE *fp2 = fopen("/home/ikramul/Desktop/201-15-14091/even_num.txt", "w");
    FILE *fp3 = fopen("/home/ikramul/Desktop/201-15-14091/odd_num.txt", "w");
    FILE *fp4 = fopen("/home/ikramul/Desktop/201-15-14091/all_bd_number.txt","w+");

    if (!fp)
    {
        printf("Source can't be opened");
        exit(-1);
    }

    fseek(fp, 0, SEEK_END);
    file_length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    program = (char *)malloc(file_length + 1);
    modified_program = (char *)malloc(file_length + 1);
    fread(program, sizeof(char), file_length, fp);
    program[file_length] = '\0';

    printf("Before removing comment:\n");
    for (i = 0; i < file_length; i++)
    {
        printf("%c", program[i]);
    }

    for (int i = 0; i < file_length; i++)
    {

        if (program[i] == '!' && program[i + 1] == '!')
        {
            s_cmt = true;
            i++;
        }

        else if (program[i] == '<' && program[i + 1] == '-')
        {
            m_cmt = true;
            i++;
        }


        else if (s_cmt == true && program[i] == '\n')
        {
            s_cmt = false;
        }

        else if (m_cmt == true && program[i] == '-' && program[i + 1] == '>')
        {
            m_cmt = false;
            i++;
        }

        else if (s_cmt || m_cmt)
            continue;

        else
        {
            modified_program[j] = program[i];
            j++;
        }
    }

    modified_program[j] = '\0';

    fputs(modified_program, fp1);
    printf("\n\n\n\nAfter removing comment:\n");
    fputs(modified_program, stdout);

    fclose(fp);

//separating number

     fseek(fp1,0,SEEK_END);
     file_length = ftell(fp1);
     fseek(fp1,0,SEEK_SET);

     program=(char*)malloc(file_length+1);
     modified_program=(char*)malloc(file_length+1);
     fread(program,sizeof(char),file_length,fp1);

     program[file_length]='\0';

     int f=0,l=0,k=0;

     for(int i=0;i<file_length;i++){

            if((program[i]=='+' && program[i+1]=='8' && program[i+2]=='8' && program[i+3]=='0') || ((program[i]==' '||program[i]=='\t') && program[i+1]=='0' && program[i+2]=='1' && program[i+3]=='7')){
                    int j=i;
                    while(program[j] != '\n'){
                        l=j;
                        j++;
                    }
                    int n=i;
                    while(program[n]!='\n'){
                        f=n;
                        n--;
                    }

                    for(int m=f;m<=l;m++){

                            if(program[m]==' ' || program[m]=='\t'){
                                continue;
                            }
                            else{
                               modified_program[k]=program[m];
                                k++;
                            }

                    }
                    modified_program[k]='\n';
                    k++;
                }

        }
        modified_program[k]='\0';

        printf("\n\n\nAll BD Number's: \n\n\n");
        fputs(modified_program,stdout);
        fputs(modified_program, fp4);

        int u=0,v,even=0,odd=0;
        for(int i=0;i<file_length;i++){

         if((modified_program[i]>='0' && modified_program[i]<='9') && modified_program[i+1]=='\n'){
                v=i;
            if(modified_program[i]=='0' || modified_program[i]=='2' || modified_program[i]=='4' || modified_program[i]=='6' || modified_program[i]=='8'){

                printf("Even Number:");
                for(int q=u;q<=v;q++){
                    printf("%c",modified_program[q]);
                    fputc(modified_program[q],fp2);
                }
                fputc(modified_program[v+1],fp2);
                printf("\n");

            }
            else{
                printf("Odd Number:");
                for(int q=u;q<=v;q++){
                    printf("%c",modified_program[q]);
                    fputc(modified_program[q],fp3);
                }
                fputc(modified_program[v+1],fp3);
                printf("\n");

            }

            u=i+2;
         }

       }

    return 0;
}
