#include "sys/time.h"
#include "sys/types.h"
#include "unistd.h"
#include "termios.h"
#include "time.h"
#include "limits.h"
#include "string.h"
#include"snake.h"
#include"hong.h"
#include"stdio.h"
#include"stdlib.h"
static struct termios ori_attr,cur_attr;
static inline int tty_reset();
static inline int kbhit();
static inline int tty_set();


/***********   about string handle function  ***********/
int control()
{
        int flag = tty_set();
        int key = 0;

        if(kbhit())
                key = getchar();
        if(flag == 0)
                tty_reset();
        return key;
}
static inline int tty_reset()
{
        if(tcsetattr(STDIN_FILENO,TCSANOW,&ori_attr) != 0)
                return -1;
        return 0;
}


static inline int tty_set()
{
        if(tcgetattr(STDIN_FILENO,&ori_attr))
                return -1;
        memcpy(&cur_attr,&ori_attr,sizeof(cur_attr));
        cur_attr.c_lflag &= ~ICANON;
        cur_attr.c_lflag &= ~ECHO;
        cur_attr.c_cc[VMIN] = 1;
        cur_attr.c_cc[VTIME] = 0;

        if(tcsetattr(STDIN_FILENO,TCSANOW,&cur_attr) != 0)
                return -1;
        return 0;
}

static inline int kbhit()
{
        fd_set rfds;
        struct timeval tv;
        int retval;

        FD_ZERO(&rfds);
        FD_SET(0,&rfds);

        tv.tv_sec = 0;
        tv.tv_usec = 0;

        retval = select(1,&rfds,NULL,NULL,&tv);

        if(retval == -1)
        {
                perror("select()");
                return 0;
        }
        else if(retval)
                return 1;
        else
                return 0;

}

int getch(void)
{
        int c=0;
        struct termios org_opts, new_opts;
        int res=0;
        //-----  store old settings -----------
        res=tcgetattr(STDIN_FILENO, &org_opts);
        //---- set new terminal parms --------
        memcpy(&new_opts, &org_opts, sizeof(new_opts));
        new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
        c=getchar();
            //------  restore old settings ---------
        res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
        return c;
}
/***********   end about string handle function  ***********/

