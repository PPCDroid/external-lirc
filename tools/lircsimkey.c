#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>
#include <linux/uinput.h>
#include <sys/time.h>
#include <unistd.h>
#include "lirc_client.h"

struct uinput_user_dev   uinp;
struct input_event	event;

char progname[] = "lircsimkey";

int main(void) {

	int ufile, retcode, i;
	struct lirc_config *config;

	ufile = open("/dev/uinput", O_WRONLY | O_NDELAY );
	printf("open /dev/uinput returned %d.\n", ufile);
	if (ufile == 0) {
			printf("Could not open uinput.\n");
			return -1;
	}

	if(lirc_init(progname,1)==-1)
			return -1;
	if(lirc_readconfig(NULL,&config,NULL)==0) //always use default config, i don't care!
	{
			char *code;
			char *c;
			int ret;

			memset(&uinp, 0, sizeof(uinp));
			strncpy(uinp.name, "Lirc SimKey", 20);
			uinp.id.version = 4;
			uinp.id.bustype = BUS_USB;

			ioctl(ufile, UI_SET_EVBIT, EV_KEY);

			for (i=0; i<KEY_MAX; i++) { //I believe this is to tell UINPUT what keys we can make?
				ioctl(ufile, UI_SET_KEYBIT, i);
			}

			// create input device in input subsystem
			retcode = write(ufile, &uinp, sizeof(uinp));
			printf("First write returned %d.\n", retcode);

			retcode = (ioctl(ufile, UI_DEV_CREATE));
			printf("ioctl UI_DEV_CREATE returned %d.\n", retcode);
			if (retcode) {
				printf("Error create uinput device %d.\n", retcode);
				return -1;
			}

			while(lirc_nextcode(&code)==0)
			{
				if(code==NULL) continue;
					while((ret=lirc_code2char(config,code,&c))==0 && c!=NULL)
					{
						int keycode = atoi(c);

						memset(&event, 0, sizeof(event));
							gettimeofday(&event.time, NULL);
							event.type = EV_KEY;
							event.code = keycode; //nomodifiers!
							event.value = 1; //key pressed
							write(ufile, &event, sizeof(event));

							memset(&event, 0, sizeof(event));
							gettimeofday(&event.time, NULL);
							event.type = EV_KEY;
							event.code = keycode;
							event.value = 0; //key released
							write(ufile, &event, sizeof(event));

							memset(&event, 0, sizeof(event));
							gettimeofday(&event.time, NULL);
							event.type = EV_SYN;
							event.code = SYN_REPORT; //not sure what this is for? i'm guessing its some kind of sync thing?
							event.value = 0;
							write(ufile, &event, sizeof(event));
					}
					free(code);
						
					if(ret==-1) break;
			}
			lirc_freeconfig(config);

			// destroy the device
			ioctl(ufile, UI_DEV_DESTROY);

			close(ufile);
	}
}
