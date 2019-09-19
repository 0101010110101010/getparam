#include "getopt.h"
#include "stdio.h"
#include "string.h"

int main(int argc ,char ** argv)
{
        int optIndex = 0;
        int opt;
        char param1[20];
        char param2[20];
        char param3[20];

        memset(param1,0 ,sizeof(param1));
        memset(param2,0 ,sizeof(param2));
        memset(param3,0 ,sizeof(param3));

        static struct option longOpts[] =
        {
                { "param1" , no_argument      , NULL, 0    },
                { "param-2", required_argument, NULL, 0    },
                { "param-3", required_argument, NULL, 0    },
                { 0        , 0                , 0   , 0    }
        };

        while((opt =getopt_long(argc,argv,"",longOpts,&optIndex))!= -1)
        {
                if(opt == 0)
                {
                        if(!strcmp(longOpts[optIndex].name,"param1"))
                        {
				;
                        }
                        if(!strcmp(longOpts[optIndex].name,"param-2"))
                        {
                                strcpy(param2, optarg);
                                printf("[%s]\n",param2);
                        }
                        if(!strcmp(longOpts[optIndex].name,"param-3"))
                        {
                                strcpy(param3, optarg);
                                printf("[%s]\n",param3);
                        }
                }
                else
                {
                        printf("param error");
                        return 0;
                }
        }
        return 0;
}

